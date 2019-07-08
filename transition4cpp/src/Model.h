//
// Created by dendy on 19-7-4.
//
#ifndef TRANSITION4CPP_MODEL_H
#define TRANSITION4CPP_MODEL_H


#include <vector>
#include <string>

#include "Object.h"

#include "State.h"
#include "Machine.h"

class State;
class Machine;

using namespace std;

class Model : public Object {
public:
    Model(string);

    void setCurrentState(State *);
    State* getCurrentState();
    string getCurrentStateName();

    void setMachine(Machine *);

    void trigger(string);

    void setEventList(vector<vector<string>> *);
    void setStateList(vector<string> *);

    void addEvent(vector<string> *);
    void addState(string);

private:
    Machine *machine;
    State *currentState;
    vector<vector<string>> eventList;
    vector<string> stateList;

    string destName;
};
#endif //TRANSITION4CPP_MODEL_H
