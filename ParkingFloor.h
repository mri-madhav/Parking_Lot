#ifndef PARKINGFLOOR_H
#define PARKINGFLOOR_H

#include <vector>
#include "ParkingSpot.h"

using namespace std;

class ParkingFloor {
private:
    int floorNumber;
    vector<ParkingSpot*> spots;

public:
    ParkingFloor(int num) : floorNumber(num) {}

    void addSpot(ParkingSpot* spot) {
        spots.push_back(spot);
    }

    vector<ParkingSpot*>& getSpots() {
        return spots;
    }

    ParkingSpot* findAvailableSpot(Vehicle* vehicle) {

        for(auto spot : spots) {

            if(!spot->isOccupied() &&
               spot->canFitVehicle(vehicle))
                return spot;
        }

        return nullptr;
    }

    bool parkVehicle(Vehicle* vehicle) {

        ParkingSpot* spot =
            findAvailableSpot(vehicle);

        if(spot == nullptr)
            return false;

        spot->parkVehicle(vehicle);

        return true;
    }

    int getFloorNumber() const {
        return floorNumber;
    }
};

#endif