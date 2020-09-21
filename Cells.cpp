#include "Cells.h"

Cells::Cells(int i=0, int j=0, double v=0) {
    row=i;
    column=j;
    vallue=v;
}
Cells::~Cells() {
    removeO()
}
void Cells::registerO (Observer* o) {
    observers.push_back(o);
}
void Cells::removeO (Observer* o) {
    observers.remove(o);
};
void Cells::notify() const {
    for(auto itr = observers.begin(); observers.end() != itr; itr++) {
        (*itr)->update();
    }
}
void Cells::setValue (double v) {
    value = v;
    notify();
}
