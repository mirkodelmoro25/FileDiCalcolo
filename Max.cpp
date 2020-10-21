#include "Max.h"
#include "Cells.h"

Max::Max(list <Cells*> s, QTableWidget* tableWidget) {
    subjects = s;
    this->tableWidget = tableWidget;
    attach();
}
Max::~Max() {
    detach();
}
 void Max::update() {
    value = op(cells);
    tableWidget->item(8, 4)->setText(QString::number(value));
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
    if (c.size() != 0) {
        max = (*(cells.begin()))->getValue();
        for (auto it:c){
            if (it->getValue() > max)
                max = it->getValue();
        }
    }
    else
        max = 0;
    return max;

}
