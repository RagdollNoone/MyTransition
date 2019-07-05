//
// Created by dendy on 19-7-4.
//

#ifndef TRANSITION4CPP_EVENT_H
#define TRANSITION4CPP_EVENT_H

#include "Object.h"

#include <string>
#include <vector>

class Transition;
class Machine;
class Model;

using namespace std;

class Event : public Object {
public:
    Event(string, Machine *, Model *);
    void addTransition(Transition *);
    bool trigger();
    void addCallback(string, Transition::callbackFunc callback);
    string getName();

private:
    bool _trigger();
    bool process(EventData *);

private:
    Machine *machine;
    Model *model;
    string name;
    vector<Transition *> transitionList;
};
#endif //TRANSITION4CPP_EVENT_H
