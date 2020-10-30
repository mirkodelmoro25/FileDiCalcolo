#ifndef FILEDICALCOLO_FUNCTIONS_H
#define FILEDICALCOLO_FUNCTIONS_H
#include <list>
class Cells;

using namespace std;

class Functions{
public:
    virtual ~Functions(){};
    virtual double op(list<Cells*> c) = 0;

protected:
    list<Cells*> cells;
};
