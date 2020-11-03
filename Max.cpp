#include <utility>
#include <iostream>
#include "Max.h"
#include "Cells.h"

Max::Max(list <Cells*> s, QTableWidget* tableWidget, int x, int y) {
    subjects = std::move(s);
    this->tableWidget = tableWidget;
    posX = x;
    posY = y;
    attach();
}

Max::~Max() {
    detach();
}

 void Max::update() {
     QTextEdit* maxC = new QTextEdit();
     maxC->setPlainText(QString::number(op(subjects)));
     tableWidget->setCellWidget(posX, posY, maxC);
}

 void Max::attach() {
     for (auto it:subjects) {
         it->registerO(this);
     }
}

 void Max::detach() {
     for (auto it:subjects) {
         it->removeO(this);
     }
}

void Max::putCells(Cells* cell) {
    subjects.push_back(cell);
}

double Max::op(list<Cells*> c) {
    double max = std::numeric_limits<double>::min();
    for (auto it:c){
        if (it->getValue() > max)
            max = it->getValue();
    }
    return max;
}
