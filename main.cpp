#include "Vehicle.h"
#include "ParkingSpot.h"
#include "ParkingFloor.h"
#include "ParkingLot.h"
#include "PaymentStrategy.h"
#include "DisplayBoard.h"

int main() {

    ParkingLot* lot = ParkingLot::getInstance();

    ParkingFloor* floor1 = new ParkingFloor(1);

    floor1->addSpot(new CarSpot(1));
    floor1->addSpot(new CarSpot(2));
    floor1->addSpot(new BikeSpot(3));
    floor1->addSpot(new TruckSpot(4));

    lot->addFloor(floor1);

    DisplayBoard board;

    board.showAvailability(lot->getFloors());

    Vehicle* car = new Car("MP04AB1234");

    Ticket* ticket = lot->parkVehicle(car);

    board.showAvailability(lot->getFloors());

    PaymentStrategy* payment = new UpiPayment();

    lot->exitVehicle(ticket, payment);

    board.showAvailability(lot->getFloors());

    return 0;
}