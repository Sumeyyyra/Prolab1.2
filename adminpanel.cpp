#include "adminpanel.h"
#include "ui_adminpanel.h"

adminpanel::adminpanel(Admin* adminInstance, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminpanel),
    admin(adminInstance)
{
    ui->setupUi(this);
    updateCompanyList();

}

adminpanel::~adminpanel()
{
    delete ui;
}

void adminpanel::on_add_clicked() {
    QString companyName = ui->nameAdd->text();
    QString companyPassword = ui->password->text();

    admin->addCompany(companyName.toStdString(), companyPassword.toStdString());
    updateCompanyList();
    emit companyListUpdated();
}

void adminpanel::updateCompanyList() {
    ui->listWidget->clear();

    const auto& companies = admin->getCompanyList();
    for (const auto& company : companies) {
        std::string companyName = company->getName();
        qDebug() << "Şirket Adı: " << QString::fromStdString(companyName); // Loglama için kontrol
        ui->listWidget->addItem(QString::fromStdString(companyName));
    }
}

void adminpanel::on_remove_clicked() {
    QListWidgetItem *selectedItem = ui->listWidget->currentItem();
    if (selectedItem) {
        QString companyName = selectedItem->text();
        admin->removeCompany(companyName.toStdString());
        updateCompanyList();
        emit companyListUpdated();

    }
}

