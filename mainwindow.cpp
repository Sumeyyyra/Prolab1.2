#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , admin(new Admin("admin", "12345"))
{
    ui->setupUi(this);

    adminPanel = new adminpanel(admin, this);
    adminPanel->setWindowFlags(Qt::Window);

    const std::vector<std::unique_ptr<Company>>& companyList = admin->getCompanyList();

    companypanel* firstCompanyPanel = nullptr;
    for (const auto& company : companyList) {
        companypanel* cpanel = new companypanel(company.get(), this);
        cpanel->setWindowFlags(Qt::Window);
        companyPanelList.push_back(cpanel);

        if (!firstCompanyPanel) {
            firstCompanyPanel = cpanel;
        }
    }

    connect(adminPanel, &adminpanel::companyListUpdated, this, &MainWindow::onCompanyListUpdated);

        cuspanel = new customerpanel();

    cuspanel->setWindowFlags(Qt::Window);
}
MainWindow::~MainWindow()
{
    delete ui;
    delete admin;
    delete adminPanel;
}

void MainWindow::updateCompanyPanelList() {


    const std::vector<std::unique_ptr<Company>>& companyList = admin->getCompanyList();

    for (const auto& company : companyList) {
        companypanel* cpanel = new companypanel(company.get(), this);
        cpanel->setWindowFlags(Qt::Window);
        companyPanelList.push_back(cpanel);


    }
}


void MainWindow::onCompanyListUpdated() {
    updateCompanyPanelList();
}
void MainWindow::on_admin_clicked()
{
    QString username = ui->adminName->text();
    QString password = ui->adminPassword->text();

    if (admin->login(username.toStdString(), password.toStdString())) {
        adminPanel->show();
    } else {
        QMessageBox::information(this, "Giriş Durumu", "Yanlış");
    }
}

void MainWindow::on_companyLog_clicked() {
    QString companyName = ui->cName->text();
    QString companyPassword = ui->cPass->text();

    for (companypanel* panel : companyPanelList) {
        Company* currentCompany = panel->getCompany();
        if (currentCompany->getName() == companyName.toStdString()) {
            if (currentCompany->login(companyName.toStdString(), companyPassword.toStdString())) {
                panel->show();
                return;
            } else {
                QMessageBox::information(this, "Giriş Durumu", "Yanlış Şifre");
                return;
            }
        }
    }

    QMessageBox::information(this, "Giriş Durumu", "Şirket Bulunamadı");
}



void MainWindow::on_customer_clicked()
{
    cuspanel->show();
}

