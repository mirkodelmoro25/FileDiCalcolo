#ifndef FILEDICALCOLO_MIN_H
#define FILEDICALCOLO_MIN_H

#include "Observer.h"
#include "Function.h"
#include <list>
#include <QtWidgets/QTableWidget>
class Cells;

class Min : public Observer, Function{
public:
    Min (list <Cells*> s, QTableWidget* tableWidget, int x, int y);
    ~Min();
    virtual void update() override;
    virtual void attach() override;
    virtual void detach() override;
    void putCells(Cells* cell);
    virtual double op(list<Cells*> c) override;

private:
    list<Cells*> subjects;
    QTableWidget* tableWidget;
    int posX, posY;
};

#endif //FILEDICALCOLO_MIN_H
