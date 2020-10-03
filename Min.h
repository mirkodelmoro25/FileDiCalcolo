#ifndef FILEDICALCOLO_MIN_H
#define FILEDICALCOLO_MIN_H


#include "Observer.h"
#include "Functions.h"

class Min : public Observer, Functions{
public:
    Min (Cells* s);
    ~Min();
    virtual void update() override;
    virtual void attach() override;
    virtual void detach() override;
    virtual double op() override;

private:
    Cells* subject;
};

#endif //FILEDICALCOLO_MIN_H
