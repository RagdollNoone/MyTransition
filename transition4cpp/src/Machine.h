//
// Created by dendy on 19-7-2.
//
#ifndef TRANSITION4CPP_MACHINE_H
#define TRANSITION4CPP_MACHINE_H

#include <string>
#include <vector>
#include <stdlib.h>

#include "Object.h"
#include "State.h"
#include "Transition.h"
#include "Event.h"

class Model;
class State;
class Event;

using namespace std;

//class Transition;

class Machine : public Object {
public:
    Machine();
    Machine(Model *);
    Machine(Model *, vector<string> *, vector<vector<string>> *, string);

    void addModel(Model *);
    void initModel(Model *);

    bool isStateExit(string);
    void addState(string);
    void addStates(vector<string> *);

    Transition* findTransition(string);
    void addTransition(vector<string> *);
    void addTransitions(vector<vector<string>> *);

    void trigger(Model *, string, string);

    void addStateCallback(string, string, State::callbackFunc);
    void addTransitionCallback(string, string, Transition::callbackFunc);

    bool setState(Model *, string);

private:
    void _addModel(Model *);
    void _addEvent(Event *);
    Event* getEvent(string name);
    State* getState(string name);

private:
    vector<Model *> modelList;
    vector<Event *> eventList;
    vector<State *> stateList;
    string initStateName;

};

#endif //TRANSITION4CPP_MACHINE_H
