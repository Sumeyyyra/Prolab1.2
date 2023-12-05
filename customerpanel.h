#ifndef CUSTOMERPANEL_H
#define CUSTOMERPANEL_H

#include <QWidget>

#include "Route.h"
#include <QMessageBox>

namespace Ui {
class customerpanel;
}

class customerpanel : public QWidget {
    Q_OBJECT

public:
    explicit customerpanel(QWidget *parent = nullptr);
    ~customerpanel();

private slots:
    void on_pushButton_clicked();

private:
    Ui::customerpanel *ui;
    Route sefer1;
    Route sefer2;
    Route sefer3;
    Route sefer4;
    Route sefer5;
    Route sefer6;
};
#endif
