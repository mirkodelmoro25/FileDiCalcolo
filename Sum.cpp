#include <utility>
#include "Sum.h"
#include "Cells.h"

Sum::Sum(list <Cells*> s, QTableWidget* tableWidget, int x, int y) {
    subjects = std::move(s);
    this->tableWidget = tableWidget;
    posX = x;
    posY = y;
    attach();
}
Sum::~Sum() {
    detach();
}

void Sum::update() {
    QTextEdit* sumC = new QTextEdit();
    sumC->setPlainText(QString::number(op(subjects)));
    tableWidget->setCellWidget(posX, posY, sumC);

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

void Sum::putCells(Cells* cell) {
    subjects.push_back(cell);
}

double Sum::op(list<Cells*> c) {
    double sum = 0;
    for (auto it:c) {
        sum += it->getValue();
    }
    return sum;
}
