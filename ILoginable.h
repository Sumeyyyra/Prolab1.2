#ifndef ILOGINABLE_H
#define ILOGINABLE_H

#include <string>

class ILoginable {
public:
    virtual ~ILoginable() {}
    virtual int login(const std::string& username, const std::string& password) = 0;
};

#endif
