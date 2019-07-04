//
// Created by dendy on 19-7-4.
//

#ifndef TRANSITION4CPP_MODEL_H
#define TRANSITION4CPP_MODEL_H

#include "Object.h"
#include "State.h"

class Model : public Object {
public:
    Model();
    void setCurrentState(State *);
    State* getCurrentState();
private:
    State *currentState;
};
#endif //TRANSITION4CPP_MODEL_H
