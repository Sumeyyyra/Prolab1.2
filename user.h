#ifndef USER_H
#define USER_H

#include "ILoginable.h"
#include <string>

class User : public ILoginable {
protected:
    std::string username;
    std::string password;

public:
    User(const std::string& username, const std::string& password);
    virtual int login(const std::string& username, const std::string& password) override;


};

#endif
