#include "Cells.h"

Cells::Cells(double v, int i, int j, QTableWidget* tableWidget) {
    value = v;
    QTextEdit* sCell = new QTextEdit();
    sCell->setPlainText(QString::number(value));
    tableWidget->setCellWidget(i, j, sCell);
    t = sCell;
   // QTableWidgetItem* q = new QTableWidgetItem("0");
    //tableWidget->setItem(i,j,QString::number(v));
    if (sumF)
        registerO(dynamic_cast<Observer *>(sumF));
    if (maxF)
        registerO(dynamic_cast<Observer *>(maxF));
    if (minF)
        registerO(dynamic_cast<Observer *>(minF));
    if (mediaF)
        registerO(dynamic_cast<Observer *>(mediaF));
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
    for(auto itr = observers.begin(); observers.end() != itr; itr++) {
        (*itr)->update();
    }
}
void Cells::setValue (double v) {
    value = v;
    notify();
}
