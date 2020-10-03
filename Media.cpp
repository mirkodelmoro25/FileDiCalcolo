#include "Media.h"

Media::Media(Cells* s) {
    subject = s;
    attach();
}
Media::~Media() {
    detach();
}
void Media::update() {
    value = op();
}
void Media::attach() {
    subject->registerO(this);
}
void Media::detach() {
    subject->removeO(this);
}
double Media::op() {
    double media = 0;
    int c = 0;
    for (auto it:cells) {
        media += it->getValue();
        c++;
    }
    media = media/c;
    return media;

}
