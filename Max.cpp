#include <utility>
#include "Max.h"
#include "Cells.h"

Max::Max(list <Cells*> s, QTableWidget* tableWidget) {
    subjects = std::move(s);
    this->tableWidget = tableWidget;
    attach();
}
Max::~Max() {
    detach();
}
 void Max::update() {
     value = op(subjects);
     QTextEdit* maxC = new QTextEdit();
     maxC->setPlainText(QString::number(value));
     tableWidget->setCellWidget(9, 7, maxC);
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
 double Max::op(list<Cells*> c) {
    double max;
    for (auto it:c){
        if (it->getValue() > max)
            max = it->getValue();
    }
    return max;
}

