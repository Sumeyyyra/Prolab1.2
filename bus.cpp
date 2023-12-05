#include "Bus.h"

Bus::Bus(const std::string& name, int numberOfSeats, int routeNumber)
    : Vehicle(name), numberOfSeats(numberOfSeats), routeNumber(routeNumber) {

}

int Bus::GetNumberOfSeats() const {
    return numberOfSeats;
}

double Bus::CalculateFuelCost(double distance) const {
    double fuelCostPerKilometer = 0.5;
    return distance * fuelCostPerKilometer;
}
int Bus::GetRouteNumber() const {
    return routeNumber;
}

