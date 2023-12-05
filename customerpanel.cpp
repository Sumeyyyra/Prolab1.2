#include "customerpanel.h"
#include "ui_customerpanel.h"

customerpanel::customerpanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::customerpanel),
    sefer1(1, {"İstanbul", "Kocaeli", "Bilecik", "Eskişehir", "Ankara"}, {75, 150, 75, 150})
    ,sefer2(2,{"İstanbul", "Kocaeli", "Bilecik", "Eskişehir","Konya"},{75,150,75,150})
    ,sefer3(3,{"İstanbul", "Kocaeli", "Ankara"},{100,400}),
    sefer4(4,{"İstanbul", "Kocaeli", "Eskişehir","Konya"},{100,200,300}),
    sefer5(5,{"İstanbul","Konya"},{300}),
    sefer6(6,{"İstanbul","Ankara"},{250})
{
    ui->setupUi(this);

}
customerpanel::~customerpanel()
{
    delete ui;
}

void customerpanel::on_pushButton_clicked()
{
    QString departure = ui->lineEdit->text();
    QString arrival = ui->lineEdit_2->text();

    Route* suitable_routes[] = {&sefer1, &sefer2, &sefer3, &sefer4, &sefer5, &sefer6};
    for (Route* route : suitable_routes) {
        bool departureFound = route->has_stop(departure.toStdString());
        bool arrivalFound = route->has_stop(arrival.toStdString());

        if (departureFound && arrivalFound) {
            int distance = route->calculate_distance(departure.toStdString(), arrival.toStdString());
            if (distance == -1) {
                distance = route->calculate_distance(arrival.toStdString(), departure.toStdString());
            }

            if (distance != -1) {
                QMessageBox::information(this,"Sefer durumu","Sefer bulundu.");
                return;
            }
        }
    }

    QMessageBox::information(this,"Sefer durumu","Sefer bulunamadı.");
}
