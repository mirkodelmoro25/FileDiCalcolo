#ifndef FOGLIODICALCOLO_CELLS_H
#define FOGLIODICALCOLO_CELLS_H
#include "Subject.h"


class Cells : public Subject {
public:
    Cells(int i=0, int j=0, double v=0);
    virtual ~Cells();
    void registerO (Observer* o) override;
    void removeO (Observer* o) override;
    void notify() const override;
    void setValue (double v);
private:
    list<Observer*> observers;
    int row;
    int column;
    double value;
};



#endif //FOGLIODICALCOLO_CELLS_H