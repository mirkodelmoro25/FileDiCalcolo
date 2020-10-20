#include "Sum.h"
#include "Cells.h"

Sum::Sum(list <Cells*> s, QTableWidget* tableWidget) {
    subjects = s;
    this->tableWidget = tableWidget;
    attach();
}
Sum::~Sum() {
    detach();
}
void Sum::update() {
    value = op(cells);
    tableWidget->item(8, 2)->setText(QString::number(value));


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
    for (auto it:c)
        sum+= it->getValue();
    return sum;
}
