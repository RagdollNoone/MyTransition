//
// Created by dendy on 19-7-2.
//

#ifndef TRANSITION4CPP_MACHINE_H
#define TRANSITION4CPP_MACHINE_H

#include <string>
#include <vector>
#include <stdlib.h>

#include "State.h"
#include "Transition.h"
#include "Condition.h"
#include "Model.h"
#include "Event.h"
#include "EventData.cpp"

using namespace std;

class Machine : public Object {
public:
    Machine();
    Machine(Model *);
    Machine(Model *, vector<string> *, vector<string[3]> *, string);

    void addModel(Model *);

    void addState(string);
    void addStates(vector<string>*);

    void addTransition(string[3]);
    void addTransitions(vector<string[3]> *);

    void trigger(Model *, string, string, string);

    void addStateCallback(string, string, State::callbackFunc);
    void addTransitionCallback(string, string, Transition::callbackFunc);

    bool setState(Model *, string);

private:
    Event* getEvent(string name);
    State* getState(string name);

private:
    vector<Model *> modelList;
    vector<Event *> eventList;
    vector<State *> stateList;
    string initStateName;

};

#endif //TRANSITION4CPP_MACHINE_H
