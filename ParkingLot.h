#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include <vector>
#include <iostream>

#include "ParkingFloor.h"
#include "Ticket.h"
#include "PaymentStrategy.h"

using namespace std;

class ParkingLot {
private:
    static ParkingLot* instance;

    vector<ParkingFloor*> floors;
    int nextTicketId;

    ParkingLot() {
        nextTicketId = 1;
    }

public:

    static ParkingLot* getInstance() {
        if(instance == nullptr) {
            instance = new ParkingLot();
        }
        return instance;
    }

    void addFloor(ParkingFloor* floor) {
        floors.push_back(floor);
    }

    vector<ParkingFloor*>& getFloors() {
        return floors;
    }

    Ticket* parkVehicle(Vehicle* vehicle) {

        for(auto floor : floors) {

            ParkingSpot* spot =
                floor->findAvailableSpot(vehicle);

            if(spot != nullptr) {

                spot->parkVehicle(vehicle);

                Ticket* ticket =
                    new Ticket(
                        nextTicketId++,
                        vehicle,
                        spot
                    );

                cout << "Vehicle parked successfully\n";
                cout << "Ticket ID: "
                     << ticket->getTicketId()
                     << endl;

                return ticket;
            }
        }

        cout << "Parking Full!\n";
        return nullptr;
    }

    void exitVehicle(
        Ticket* ticket,
        PaymentStrategy* payment
    ) {

        ParkingSpot* spot =
            ticket->getSpot();

        spot->removeVehicle();

        double amount = 100.0;

        payment->pay(amount);

        cout << "Vehicle exited successfully\n";
    }
};

ParkingLot* ParkingLot::instance = nullptr;

#endif