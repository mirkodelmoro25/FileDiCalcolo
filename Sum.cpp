
#include <iostream>
#include <utility>
#include "Sum.h"
#include "Cells.h"

Sum::Sum(list <Cells*> s, QTableWidget* tableWidget) {
    subjects = std::move(s);
    this->tableWidget = tableWidget;
    attach();
}
Sum::~Sum() {
    detach();
}


void Sum::update() {
    value = op(subjects);
    QTextEdit* sumC = new QTextEdit();
    sumC->setPlainText(QString::number(value));
    tableWidget->setCellWidget(9, 6, sumC);

}
void Sum::attach() {
    for (auto it:subjects) {
        it->registerO(this);
    }
}
void Sum::detach() {
    for (auto it:subjects) {
        it->removeO(this);
    }
}
double Sum::op(list<Cells*> c) {
    double sum = 0;
    for (auto it:c) {
        sum += it->getValue();
    }
    return sum;
}
