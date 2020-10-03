#include "Max.h"

Max::Max(Cells* s) {
    subject = s;
    attach();
}
Max::~Max() {
    detach();
}
 void Max::update() {
    value = op();
}
 void Max::attach() {
    subject->registerO(this);
}
 void Max::detach() {
    subject->removeO(this);
}
 double Max::op() {
    double max;
    if (cells.size() != 0) {
        max = (*(cells.begin()))->getValue();
        for (auto it:cells){
            if (it->getValue() > max)
                max = it->getValue();
        }
    }
    else
        max = 0;
    return max;

}
