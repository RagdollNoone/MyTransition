//
// Created by dendy on 19-7-3.
//
#ifndef TRANSITION4CPP_TRANSITION_H
#define TRANSITION4CPP_TRANSITION_H

#include <string>
#include <vector>

#include "Object.h"
#include "State.h"

class State;
class Condition;
class EventData;

using namespace std;

class Transition : public Object {
public:
    typedef void (*callbackFunc)(EventData *);

public:
    Transition(const string, State*, State*);
    bool execute(EventData &);
    void addBeforeCallback(const callbackFunc);
    void addAfterCallback(const callbackFunc);
    void addPrepareCallback(const callbackFunc);
    string getTriggerName();
    string getSrcName();
    void changeDestState(State *);

private:
    void changeState(EventData &);

private:
    string name;
    State *source;
    State *dest;
    vector<Condition *> conditionList;
    vector<callbackFunc> beforeFuncList;
    vector<callbackFunc> afterFuncList;
    vector<callbackFunc> prepareFuncList;
};
#endif //TRANSITION4CPP_TRANSITION_H
