#ifndef FILEDICALCOLO_SUM_H
#define FILEDICALCOLO_SUM_H

#include "Observer.h"
#include "Function.h"
#include <list>
#include <QtWidgets/QTableWidget>
class Cells;

class Sum :  public Observer, public Function{
public:
    Sum (list <Cells*> s, QTableWidget* tableWidget);
    ~Sum();
    virtual void update() override;
    virtual void attach() override;
    virtual void detach() override;
    void putCells(Cells* cell);
    virtual double op(list<Cells*> c) override;

private:
    list<Cells*> subjects;
    QTableWidget* tableWidget;
};

#endif //FILEDICALCOLO_MIN_H
