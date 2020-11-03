#include <utility>
#include "Media.h"
#include "Cells.h"

Media::Media(list <Cells*> s, QTableWidget* tableWidget, int x, int y) {
    subjects = std::move(s);
    this->tableWidget = tableWidget;
    posX = x;
    posY = y;
    attach();
}

Media::~Media() {
    detach();
}

void Media::update() {
    QTextEdit* mediaC = new QTextEdit();
    mediaC->setPlainText(QString::number(op(subjects)));
    tableWidget->setCellWidget(posX, posY, mediaC);
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

void Media::putCells(Cells* cell) {
    subjects.push_back(cell);
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
