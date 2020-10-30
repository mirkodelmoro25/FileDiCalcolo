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
    virtual ~Cells() {};
    void registerO (Observer * o) override;
    void removeO (Observer * o) override;
    void notify() const override;
    void setValue (double v);
    double getValue() const { return value;}
    QLineEdit* getCell() {return t;}
    int getRow() const {return row;}
    int getColumn() const {return column;}
    void setRegistered(bool r) {registered = r;}
    bool getRegistered() const {return registered;}

private:
    list<Observer*> observers;
    double value;
    Sum* sumF;
    Max* maxF;
    Min* minF;
    Media* mediaF;
    QLineEdit* t;
    int row;
    int column;
    bool registered;
};
