#include "Airplane.h"

Airplane::Airplane(const std::string& name, int maxAltitude, int numberOfEngines)
    : Vehicle(name), maxAltitude(maxAltitude), numberOfEngines(numberOfEngines) {}

int Airplane::GetMaxAltitude() const {
    return maxAltitude;
}

int Airplane::GetNumberOfEngines() const {
    return numberOfEngines;
}

int Airplane::GetNumberOfSeats() const {

}

double Airplane::CalculateFuelCost(double distance) const {

}
