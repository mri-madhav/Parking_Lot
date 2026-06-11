#ifndef PARKINGSPOT_H
#define PARKINGSPOT_H

#include "Vehicle.h"

class ParkingSpot {
protected:
    int spotId;
    bool occupied;
    Vehicle* vehicle;

public:
    ParkingSpot(int id)
        : spotId(id), occupied(false), vehicle(nullptr) {}

    virtual ~ParkingSpot() {}

    virtual bool canFitVehicle(Vehicle* v) = 0;

    virtual VehicleType getSpotType() = 0;

    void parkVehicle(Vehicle* v) {
        vehicle = v;
        occupied = true;
    }

    void removeVehicle() {
        vehicle = nullptr;
        occupied = false;
    }

    bool isOccupied() const {
        return occupied;
    }

    int getSpotId() const {
        return spotId;
    }
};

class BikeSpot : public ParkingSpot {
public:
    BikeSpot(int id) : ParkingSpot(id) {}

    bool canFitVehicle(Vehicle* v) override {
        return v->getType() == VehicleType::BIKE;
    }

    VehicleType getSpotType() override {
        return VehicleType::BIKE;
    }
};

class CarSpot : public ParkingSpot {
public:
    CarSpot(int id) : ParkingSpot(id) {}

    bool canFitVehicle(Vehicle* v) override {
        return v->getType() == VehicleType::CAR;
    }

    VehicleType getSpotType() override {
        return VehicleType::CAR;
    }
};

class TruckSpot : public ParkingSpot {
public:
    TruckSpot(int id) : ParkingSpot(id) {}

    bool canFitVehicle(Vehicle* v) override {
        return v->getType() == VehicleType::TRUCK;
    }

    VehicleType getSpotType() override {
        return VehicleType::TRUCK;
    }
};

#endif