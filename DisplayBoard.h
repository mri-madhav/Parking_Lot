#ifndef DISPLAYBOARD_H
#define DISPLAYBOARD_H

#include <iostream>
#include <vector>

#include "ParkingFloor.h"

using namespace std;

class DisplayBoard {
public:

    void showAvailability(vector<ParkingFloor*>& floors) {

        int bikeCount = 0;
        int carCount = 0;
        int truckCount = 0;

        for(auto floor : floors) {

            for(auto spot : floor->getSpots()) {

                if(spot->isOccupied())
                    continue;

                if(spot->getSpotType() == VehicleType::BIKE)
                    bikeCount++;

                else if(spot->getSpotType() == VehicleType::CAR)
                    carCount++;

                else if(spot->getSpotType() == VehicleType::TRUCK)
                    truckCount++;
            }
        }

        cout << "\n===== DISPLAY BOARD =====\n";

        cout << "Available Bike Spots  : "
             << bikeCount << endl;

        cout << "Available Car Spots   : "
             << carCount << endl;

        cout << "Available Truck Spots : "
             << truckCount << endl;

        cout << "=========================\n";
    }
};

#endif