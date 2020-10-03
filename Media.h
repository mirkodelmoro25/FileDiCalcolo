#ifndef FILEDICALCOLO_MEDIA_H
#define FILEDICALCOLO_MEDIA_H


#include "Observer.h"
#include "Functions.h"

class Media : public Observer, Functions{
public:
    Media (Cells* s);
    ~Media();
    virtual void update() override;
    virtual void attach() override;
    virtual void detach() override;
    virtual double op() override;

private:
    Cells* subject;
};


#endif //FILEDICALCOLO_MEDIA_H
