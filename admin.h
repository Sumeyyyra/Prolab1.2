#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "Company.h"
#include <vector>
#include <memory>
#include <algorithm>

class Admin : public User {

private:
    std::vector<std::unique_ptr<Company>> companyList;
public:
    Admin(const std::string& username, const std::string& password);
    void addCompany(const std::string& companyName, const std::string& companyPassword);
    virtual int login(const std::string& username, const std::string& password) override;
    const std::vector<std::unique_ptr<Company>>& getCompanyList() const;
    void removeCompany(const std::string& companyName);
};



#endif
