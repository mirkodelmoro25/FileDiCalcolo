//
// Created by mirko25 on 03/10/20.
//
#include <utility>
#include "Min.h"
#include "Cells.h"

Min::Min(list <Cells*> s, QTableWidget* tableWidget) {
    subjects = std::move(s);
    this->tableWidget = tableWidget;
    attach();
}
Min::~Min() {
    detach();
}
void Min::update() {
    value = op(subjects);
    QTextEdit* minC = new QTextEdit();
    minC->setPlainText(QString::number(value));
    tableWidget->setCellWidget(9, 8, minC);
}
void Min::attach() {
    for (auto it:subjects) {
        it->registerO(this);
    }
}
void Min::detach() {
    for (auto it:subjects) {
        it->removeO(this);
    }
}
double Min::op(list<Cells*> c) {
    double min;
    for (auto it:c){
        if (it->getValue() <= min)
            min = it->getValue();
    }
    return min;

}
