#include "Sum.h"

Sum::Sum(Cells* s) {
    subject = s;
    attach();
}
Sum::~Sum() {
    detach();
}
void Sum::update() {
    value = op();
}
void Sum::attach() {
    subject->registerO(this);
}
void Sum::detach() {
    subject->removeO(this);
}
double Sum::op() {
    double sum = 0;
    for (auto it:cells)
        sum+= it->getValue();
    return sum;

}
