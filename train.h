#ifndef TRAIN_H
#define TRAIN_H

#include "Vehicle.h"
#include <string>

class Train : public Vehicle {
private:
    int numberOfCarriages;
    bool isElectric;

public:
    Train(const std::string& name, int numberOfCarriages, bool isElectric);

    int GetNumberOfCarriages() const;
    bool GetIsElectric() const;
    int GetNumberOfSeats() const override;
    double CalculateFuelCost(double distance) const override;
};

#endif
