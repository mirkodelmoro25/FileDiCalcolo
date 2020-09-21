//
// Created by mirko25 on 17/09/20.
//

#ifndef FOGLIODICALCOLO_OBSERVER_H
#define FOGLIODICALCOLO_OBSERVER_H

public class Observer {
protected:
    virtual ~Observer() {}
public:
    virtual void update() = 0;
    virtual void attach() = 0;
    virtual void detach() = 0;


};

#endif //FOGLIODICALCOLO_OBSERVER_H
