#include "Train.h"

Train::Train(const std::string& name, int numberOfCarriages, bool isElectric)
    : Vehicle(name), numberOfCarriages(numberOfCarriages), isElectric(isElectric) {}

int Train::GetNumberOfCarriages() const {
    return numberOfCarriages;
}

bool Train::GetIsElectric() const {
    return isElectric;
}

int Train::GetNumberOfSeats() const {
}

double Train::CalculateFuelCost(double distance) const {
}
