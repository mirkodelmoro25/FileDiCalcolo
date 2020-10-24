#include <utility>
#include "Media.h"
#include "Cells.h"

Media::Media(list <Cells*> s, QTableWidget* tableWidget) {
    subjects = std::move(s);
    this->tableWidget = tableWidget;
    attach();
}
Media::~Media() {
    detach();
}
void Media::update() {
    value = op(subjects);
    QTextEdit* mediaC = new QTextEdit();
    mediaC->setPlainText(QString::number(value));
    tableWidget->setCellWidget(9, 9, mediaC);
}
void Media::attach() {
    for (auto it:subjects) {
        it->registerO(this);
    }
}
void Media::detach() {
    for (auto it:subjects) {
        it->removeO(this);
    }
}
double Media::op(list<Cells*> c) {
    double media = 0;
    int count = 0;
    for (auto it:c) {
        media += it->getValue();
        count++;
    }
    media = media/count;
    return media;
}
