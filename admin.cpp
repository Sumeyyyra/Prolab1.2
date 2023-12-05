#include "Admin.h"

Admin::Admin(const std::string& username, const std::string& password)
    : User(username, password) {
    addCompany("A","A");
    addCompany("B","B");
    addCompany("C","C");
    addCompany("D","D");
    addCompany("F","F");


}

int Admin::login(const std::string& username, const std::string& password) {
    if (this->username == username && this->password == password) {
        return 1;
    } else {
        return 0;
    }
}

void Admin::addCompany(const std::string& companyName, const std::string& companyPassword) {
    companyList.push_back(std::make_unique<Company>(companyName, companyPassword));
}

const std::vector<std::unique_ptr<Company>>& Admin::getCompanyList() const {
    return companyList;
}

void Admin::removeCompany(const std::string& companyName) {
    auto it = std::remove_if(companyList.begin(), companyList.end(),
                             [&](const std::unique_ptr<Company>& company) {
                                 return company->getName() == companyName;
                             });

    if (it != companyList.end()) {
        companyList.erase(it, companyList.end());
    }
}
