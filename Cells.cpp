#include "Cells.h"

Cells::Cells(int i, int j, double v) {
    row=i;
    column=j;
    value=v;
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
