#include "Company.h"

Company::Company(const std::string& name, const std::string& password)
    : User(name, password), name(name) {}

Company::~Company() {

    for (auto bus : buses) {
        delete bus;
    }


    for (auto airplane : airplanes) {
        delete airplane;
    }


    for (auto train : trains) {
        delete train;
    }
}

const std::string& Company::getName() const {
    return name;
}

const std::vector<Bus*>& Company::getBuses() const {
    return buses;
}


void Company::addBus(const std::string& name, int numberOfSeats, int routeNumber) {
    buses.push_back(new Bus(name, numberOfSeats, routeNumber));
}

void Company::addAirplane(const std::string& name, int maxAltitude, int numberOfEngines) {
    airplanes.push_back(new Airplane(name, maxAltitude, numberOfEngines));
}


const std::vector<Airplane*>& Company::getAirplanes() const {
    return airplanes;
}

void Company::addTrain(const std::string& name, int numberOfCarriages, bool isElectric) {
    trains.push_back(new Train(name, numberOfCarriages, isElectric));
}


const std::vector<Train*>& Company::getTrains() const {
    return trains;
}

void Company::removeAirplane(const std::string& airplaneName) {
    auto it = std::find_if(airplanes.begin(), airplanes.end(), [&](const Airplane* airplane) {
        return airplane->GetName() == airplaneName;
    });
    if (it != airplanes.end()) {
        delete *it;
        airplanes.erase(it);
    }
}

void Company::removeBus(const std::string& busName) {
    auto it = std::find_if(buses.begin(), buses.end(), [&](const Bus* bus) {
        return bus->GetName() == busName;
    });
    if (it != buses.end()) {
        delete *it;
        buses.erase(it);
    }
}

void Company::removeTrain(const std::string& trainName) {
    auto it = std::find_if(trains.begin(), trains.end(), [&](const Train* train) {
        return train->GetName() == trainName;
    });
    if (it != trains.end()) {
        delete *it;
        trains.erase(it);
    }
}
