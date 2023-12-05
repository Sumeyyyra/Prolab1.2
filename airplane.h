#ifndef AIRPLANE_H
#define AIRPLANE_H

#include "Vehicle.h"
#include <string>

class Airplane : public Vehicle {
private:
    int maxAltitude;
    int numberOfEngines;

public:
    Airplane(const std::string& name, int maxAltitude, int numberOfEngines);

    int GetMaxAltitude() const;
    int GetNumberOfEngines() const;
    int GetNumberOfSeats() const override;
    double CalculateFuelCost(double distance) const override;
};

#endif // AIRPLANE_H
