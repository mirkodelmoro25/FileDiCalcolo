#ifndef FILEDICALCOLO_FUNCTIONS_H
#define FILEDICALCOLO_FUNCTIONS_H
#include "Cells.h"
#include <list>

using namespace std;

class Functions{
public:
    virtual double op() = 0;


protected:
    double value;
    list<Cells*> cells;
};


#endif //FILEDICALCOLO_FUNCTIONS_H
