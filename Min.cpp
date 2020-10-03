#include "Min.h"

Min::Min(Cells* s) {
    subject = s;
    attach();
}
Min::~Min() {
    detach();
}
void Min::update() {
    value = op();
}
void Min::attach() {
    subject->registerO(this);
}
void Min::detach() {
    subject->removeO(this);
}
double Min::op() {
    double min;
    if (cells.size() != 0) {
        min = (*(cells.begin()))->getValue();
        for (auto it:cells){
            if (it->getValue() < min)
                min = it->getValue();
        }
    }
    else
        min = 0;
    return min;

}
