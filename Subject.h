//
// Created by mirko25 on 17/09/20.
//

#ifndef FOGLIODICALCOLO_SUBJECT_H
#define FOGLIODICALCOLO_SUBJECT_H

class Subject {
protected:
    virtual ~Subject() {}
public:
    virtual void registerO (Observer* o) = 0;
    virtual void removeO (Observer* o) = 0;
    virtual void notify() const = 0;


};

#endif //FOGLIODICALCOLO_SUBJECT_H
