#include <QtWidgets/QLineEdit>
#include <iostream>
#include "Cells.h"

Cells::Cells(double v, int i, int j, QTableWidget* tableWidget) {
    value = v;
    row = i;
    column = j;
    registered = false;
    QTableWidgetItem* q = new QTableWidgetItem("");
    tableWidget->setItem(i,j,q);

}

void Cells::registerO (Observer* o) {
    observers.push_back(o);
}

void Cells::removeO (Observer* o) {
    observers.remove(o);
}

void Cells::notify() const {
    for(auto it: observers) {
        it->update();
    }
}

void Cells::setValue (double v) {
    value = v;
    notify();
}
