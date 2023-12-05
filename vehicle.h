#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle {
private:
    std::string name;

public:
    Vehicle(const std::string& name);

    virtual int GetNumberOfSeats() const = 0;
    virtual double CalculateFuelCost(double distance) const = 0;
    const std::string& GetName() const { return name; }
};

#endif // VEHICLE_H
