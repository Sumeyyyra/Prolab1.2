#ifndef BUS_H
#define BUS_H

#include "Vehicle.h"
#include <string>

class Bus : public Vehicle {
private:
    int numberOfSeats;
    int routeNumber;

public:
    Bus(const std::string& name, int numberOfSeats, int routeNumber);  // Ek parametrelerle genişletilmiş kurucu

    int GetNumberOfSeats() const override;
    double CalculateFuelCost(double distance) const override;
    int GetRouteNumber() const;

};

#endif
