#ifndef TICKET_H
#define TICKET_H

#include <ctime>
#include "Vehicle.h"
#include "ParkingSpot.h"

class Ticket {
private:
    int ticketId;
    Vehicle* vehicle;
    ParkingSpot* spot;
    time_t entryTime;

public:
    Ticket(int id, Vehicle* v, ParkingSpot* s)
        : ticketId(id),
          vehicle(v),
          spot(s),
          entryTime(time(nullptr)) {}

    int getTicketId() const {
        return ticketId;
    }

    Vehicle* getVehicle() const {
        return vehicle;
    }

    ParkingSpot* getSpot() const {
        return spot;
    }

    time_t getEntryTime() const {
        return entryTime;
    }
};

#endif