#include "companypanel.h"
#include "ui_companypanel.h"

companypanel::companypanel(Company* company, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::companypanel),
    company(company)
{
    ui->setupUi(this);
    if (company->getName() == "A") {
        company->addBus("oto1", 20, 3);
    company->addBus("oto2",15, 3);
}
    if (company->getName() == "B") {
    company->addBus("oto1", 15, 3);
    company->addBus("oto2",20, 4);
    }
    if (company->getName() == "C") {
    company->addBus("oto1", 20, 4);
    company->addAirplane("uçak1",30, 5);
    company->addAirplane("uçak2",30, 5);

    }
    if (company->getName() == "D") {
    company->addTrain("Tren1", 25, 1);
    company->addTrain("Tren2", 25, 2);
    company->addTrain("Tren3", 25, 2);

    }
    if (company->getName() == "F") {
    company->addAirplane("Uçak1", 30, 6);
    company->addAirplane("Uçak2", 30 ,6);
    }
    updateBusList();
    updateAirplaneList();
    updateTrainList();
}

companypanel::~companypanel()
{
    delete ui;
    delete company;

}

void companypanel::updateBusList() {
    ui->listWidget->clear();

    const std::vector<Bus*>& buses = company->getBuses();
    for (const Bus* bus : buses) {
    std::string listItem = bus->GetName();
                           + " - Koltuk Sayısı: " + QString::number(bus->GetNumberOfSeats())
                           + ", Sefer Numarası: " + QString::number(bus->GetRouteNumber());
                                     ui->listWidget->addItem(QString::fromStdString(listItem));
    }
}

void companypanel::on_pushButton_clicked()
{
    std::string busName = ui->name->text().toStdString();
    int seatCount = ui->seatCount->text().toInt();
    int routeNumber = ui->seferSayisi->text().toInt();


    company->addBus(busName, seatCount, routeNumber);


updateBusList();
}

void companypanel::updateAirplaneList() {


const std::vector<Airplane*>& airplanes = company->getAirplanes();
ui->listWidget_2->clear();
for (const Airplane* airplane : airplanes) {
        std::string listItem = airplane->GetName();
                           + " - Koltuk Sayısı: " + QString::number(airplane->GetMaxAltitude())
                           + ", Sefer Numarası: " + QString::number(airplane->GetNumberOfEngines());
                                                    ui->listWidget_2->addItem(QString::fromStdString(listItem));
}
}

void companypanel::updateTrainList() {

ui->listWidget_3->clear();
const std::vector<Train*>& trains = company->getTrains();
for (const Train* train : trains) {
        std::string listItem =train->GetName();
                           + " Koltuk Sayısı: " + QString::number(train->GetNumberOfCarriages())
                           + ", Sefer Numarası: " + (train->GetIsElectric() ? "Yes" : "No");
                                     ui->listWidget_3->addItem(QString::fromStdString(listItem));
}
}

void companypanel::on_pushButton_2_clicked()
{
std::string airplaneName = ui->name_2->text().toStdString();
int maxAltitude = ui->seatCount_2->text().toInt();
int numberOfEngines = ui->seferSayisi_2->text().toInt();

company->addAirplane(airplaneName, maxAltitude, numberOfEngines);

updateAirplaneList();

}

void companypanel::on_pushButton_3_clicked()
{
std::string trainName = ui->name_3->text().toStdString();
int numberOfCarriages = ui->seatCount_3->text().toInt();
int sefer = ui->seferSayisi_3->text().toInt();

company->addTrain(trainName, numberOfCarriages, sefer);

updateTrainList();

}




void companypanel::on_pushButton_4_clicked()
{
QListWidgetItem *selectedItem = ui->listWidget->currentItem();
if (selectedItem) {
        QString busName = selectedItem->text();
        company->removeBus(busName.toStdString());
        updateBusList();

}
}


void companypanel::on_pushButton_5_clicked()
{
QListWidgetItem *selectedItem = ui->listWidget_2->currentItem();
if (selectedItem) {
        QString airplaneName = selectedItem->text();
        company->removeAirplane(airplaneName.toStdString());
        updateAirplaneList();

}
}


void companypanel::on_pushButton_6_clicked()
{
QListWidgetItem *selectedItem = ui->listWidget_3->currentItem();
if (selectedItem) {
        QString trainName = selectedItem->text();
        company->removeTrain(trainName.toStdString());
        updateTrainList();

}
}
