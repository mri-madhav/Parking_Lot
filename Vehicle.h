#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

using namespace std;

enum class VehicleType {
    BIKE,
    CAR,
    TRUCK
};

class Vehicle {
protected:
    string licensePlate;
    VehicleType type;

public:
    Vehicle(string plate, VehicleType t)
        : licensePlate(plate), type(t) {}

    virtual ~Vehicle() {}

    VehicleType getType() const {
        return type;
    }

    string getLicensePlate() const {
        return licensePlate;
    }
};

class Bike : public Vehicle {
public:
    Bike(string plate)
        : Vehicle(plate, VehicleType::BIKE) {}
};

class Car : public Vehicle {
public:
    Car(string plate)
        : Vehicle(plate, VehicleType::CAR) {}
};

class Truck : public Vehicle {
public:
    Truck(string plate)
        : Vehicle(plate, VehicleType::TRUCK) {}
};

#endif