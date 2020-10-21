#ifndef FILEDICALCOLO_MAX_H
#define FILEDICALCOLO_MAX_H

#include "Observer.h"
#include "Functions.h"
#include <list>
#include <QtWidgets/QTableWidget>
class Cells;

class Max : public Observer, Functions {
public:
    Max (list <Cells*> s, QTableWidget* tableWidget);
    ~Max();
    virtual void update() override;
    virtual void attach() override;
    virtual void detach() override;
    virtual double op(list<Cells*> c) override;

private:
    list <Cells*> subjects;
    QTableWidget* tableWidget;
};


#endif //FILEDICALCOLO_MAX_H
