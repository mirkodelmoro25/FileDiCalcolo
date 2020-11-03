#ifndef FILEDICALCOLO_MAX_H
#define FILEDICALCOLO_MAX_H

#include "Observer.h"
#include "Function.h"
#include <list>
#include <QtWidgets/QTableWidget>
class Cells;

class Max : public Observer, Function {
public:
    Max (list <Cells*> s, QTableWidget* tableWidget, int x, int y);
    ~Max();
    virtual void update() override;
    virtual void attach() override;
    virtual void detach() override;
    void putCells(Cells* cell);
    virtual double op(list<Cells*> c) override;

private:
    list <Cells*> subjects;
    QTableWidget* tableWidget;
    int posX, posY;
};

#endif //FILEDICALCOLO_MAX_H
