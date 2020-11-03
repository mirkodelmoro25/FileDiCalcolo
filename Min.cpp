#include <utility>
#include "Min.h"
#include "Cells.h"

Min::Min(list <Cells*> s, QTableWidget* tableWidget, int x, int y) {
    subjects = std::move(s);
    this->tableWidget = tableWidget;
    posX = x;
    posY = y;
    attach();
}

Min::~Min() {
    detach();
}

void Min::update() {
    QTextEdit* minC = new QTextEdit();
    minC->setPlainText(QString::number(op(subjects)));
    tableWidget->setCellWidget(posX, posY, minC);
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

void Min::putCells(Cells* cell) {
    subjects.push_back(cell);
}

double Min::op(list<Cells*> c) {
    double min = std::numeric_limits<double>::max();
    for (auto it:c){
        if (it->getValue() <= min)
            min = it->getValue();
    }
    return min;
}
