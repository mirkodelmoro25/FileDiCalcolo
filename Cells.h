//
// Created by mirko25 on 18/09/20.
//

#ifndef FOGLIODICALCOLO_CELLS_H
#define FOGLIODICALCOLO_CELLS_H
#include "Subject.h"
#include <list>
#include "Sum.h"
#include "Max.h"
#include "Min.h"
#include "Media.h"
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>


using namespace std;

class Cells : public Subject {
public:
    Cells (double v, int i, int j, QTableWidget* tableWidget);
    virtual ~Cells();
    void registerO (Observer * o) override;
    void removeO (Observer * o) override;
    void notify() const override;
    void setValue (double v);
    double getValue() { return value;}
    QTextEdit* getCell() {return t;}

private:
    list<Observer*> observers;
    double value;
    Sum* sumF;
    Max* maxF;
    Min* minF;
    Media* mediaF;
    QTextEdit* t;

};



#endif //FOGLIODICALCOLO_CELLS_H

