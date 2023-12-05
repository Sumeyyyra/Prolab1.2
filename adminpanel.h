#ifndef ADMINPANEL_H
#define ADMINPANEL_H

#include <QWidget>
#include "Admin.h"
#include "company.h"

namespace Ui {
class adminpanel;
}

class adminpanel : public QWidget
{
    Q_OBJECT

public:
    explicit adminpanel(Admin* adminInstance, QWidget *parent = nullptr); // Admin nesnesini alacak bir constructor
    ~adminpanel();

private slots:
    void on_add_clicked();
    void updateCompanyList();
    void on_remove_clicked();

signals:
    void companyListUpdated();

private:
    Ui::adminpanel *ui;
    Admin* admin;

};

#endif
