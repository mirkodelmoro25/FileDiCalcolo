#ifndef FILEDICALCOLO_MIN_H
#define FILEDICALCOLO_MIN_H


#include "Observer.h"
#include "Functions.h"
#include <list>
#include <QtWidgets/QTableWidget>
class Cells;

class Min : public Observer, Functions{
public:
    Min (list <Cells*> s, QTableWidget* tableWidget);
    ~Min();
    virtual void update() override;
    virtual void attach() override;
    virtual void detach() override;
    virtual double op(list<Cells*> c) override;

private:
    list<Cells*> subjects;
    QTableWidget* tableWidget;
};

#endif //FILEDICALCOLO_MIN_H
