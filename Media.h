#ifndef FILEDICALCOLO_MEDIA_H
#define FILEDICALCOLO_MEDIA_H

#include "Observer.h"
#include "Function.h"
#include <list>
#include <QtWidgets/QTableWidget>
class Cells;

class Media : public Observer, Function{
public:
    Media (list <Cells*> s, QTableWidget* tableWidget);
    ~Media();
    virtual void update() override;
    virtual void attach() override;
    virtual void detach() override;
    void putCells(Cells* cell);
    virtual double op(list<Cells*> c) override;

private:
    list<Cells*> subjects;
    QTableWidget* tableWidget;
};

#endif //FILEDICALCOLO_MEDIA_H
