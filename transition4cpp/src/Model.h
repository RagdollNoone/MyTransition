//
// Created by dendy on 19-7-4.
//

#ifndef TRANSITION4CPP_MODEL_H
#define TRANSITION4CPP_MODEL_H


#include <vector>
#include <string>

#include "Object.h"

class State;
class Machine;

using namespace std;

class Model : public Object {
public:
    Model();

    void setCurrentState(State *);
    State* getCurrentState();
    string getCurrentStateName();

    void setMachine(Machine *);

    void trigger(string);

    void setEventList();
    void setStateList();

private:
    Machine *machine;
    State *currentState;
    vector<string[3]> eventList;
    vector<string> stateList;

    string destName;
};
#endif //TRANSITION4CPP_MODEL_H
