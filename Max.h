#ifndef FILEDICALCOLO_MAX_H
#define FILEDICALCOLO_MAX_H


#include "Observer.h"
#include "Functions.h"

class Max : public Observer, Functions{
public:
    Max (Cells* s);
    ~Max();
    virtual void update() override;
    virtual void attach() override;
    virtual void detach() override;
    virtual double op() override;

private:
    Cells* subject;
};


#endif //FILEDICALCOLO_MAX_H
