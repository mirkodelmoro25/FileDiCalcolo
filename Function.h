#ifndef FILEDICALCOLO_FUNCTION_H
#define FILEDICALCOLO_FUNCTION_H
#include <list>
class Cells;

using namespace std;

class Function{
public:
    virtual ~Function(){};
    virtual double op(list<Cells*> c) = 0;

protected:
    list<Cells*> cells;
};
