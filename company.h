#ifndef COMPANY_H
#define COMPANY_H

#include "User.h"
#include "Bus.h"
#include "Airplane.h"
#include "Train.h"
#include <string>
#include <vector>
#include <algorithm>

class Company : public User {
private:
    std::string name;
    std::vector<Bus*> buses;
    std::vector<Airplane*> airplanes;
    std::vector<Train*> trains;

public:
    void removeBus(const std::string& busName);
    void removeAirplane(const std::string& airplaneName);
    void removeTrain(const std::string& trainName);
    Company(const std::string& name, const std::string& password);
    ~Company();

    void addBus(const std::string& name, int numberOfSeats, int routeNumber);
    const std::vector<Bus*>& getBuses() const;


    void addAirplane(const std::string& name, int maxAltitude, int numberOfEngines);
    const std::vector<Airplane*>& getAirplanes() const;


    void addTrain(const std::string& name, int numberOfCarriages, bool isElectric);
    const std::vector<Train*>& getTrains() const;

    const std::string& getName() const;
};

#endif
