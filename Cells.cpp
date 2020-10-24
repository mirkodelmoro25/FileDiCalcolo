#include <QtWidgets/QLineEdit>
#include <iostream>
#include "Cells.h"

Cells::Cells(double v, int i, int j, QTableWidget* tableWidget) {
    value = v;
    row = i;
    column = j;
    QTableWidgetItem* q = new QTableWidgetItem("0");
    q->setData(Qt::EditRole, value);
    tableWidget->setItem(i,j,q);
    
}

Cells::~Cells() noexcept {
    if (sumF)
        removeO(dynamic_cast<Observer *>(sumF));
    if (maxF)
        removeO(dynamic_cast<Observer *>(maxF));
    if (minF)
        removeO(dynamic_cast<Observer *>(minF));
    if (mediaF)
        removeO(dynamic_cast<Observer *>(mediaF));
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
