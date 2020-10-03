#ifndef FILEDICALCOLO_SUM_H
#define FILEDICALCOLO_SUM_H


#include "Observer.h"
#include "Functions.h"

class Sum : public Observer, Functions{
public:
    Sum (Cells* s);
    ~Sum();
    virtual void update() override;
    virtual void attach() override;
    virtual void detach() override;
    virtual double op() override;

private:
    Cells* subject;
};

#endif //FILEDICALCOLO_MIN_H


