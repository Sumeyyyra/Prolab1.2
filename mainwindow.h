#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "admin.h"
#include "adminpanel.h"
#include "company.h"
#include "companypanel.h"
#include "customerpanel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_admin_clicked();
    void updateCompanyPanelList();
    void on_companyLog_clicked();
    void onCompanyListUpdated();

    void on_customer_clicked();

private:
    Ui::MainWindow *ui;
    Admin *admin;
    adminpanel *adminPanel;
    Company *company;
    std::vector<companypanel*> companyPanelList;
    customerpanel *cuspanel;

};
#endif // MAINWINDOW_H
