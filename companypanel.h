#ifndef COMPANYPANEL_H
#define COMPANYPANEL_H

#include <QWidget>
#include "company.h"

namespace Ui {
class companypanel;
}

class companypanel : public QWidget
{
    Q_OBJECT

public:
    explicit companypanel(Company *company ,QWidget *parent = nullptr);
    ~companypanel();
    std::string getCompanyName() const {
        return company->getName();
    }
    Company* getCompany() {
        return company;
    }

private slots:
    void on_pushButton_clicked();
    void updateBusList();
    void updateTrainList();
    void on_pushButton_2_clicked();
    void updateAirplaneList();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::companypanel *ui;
    Company *company;
};

#endif
