//
// Created by dendy on 19-7-3.
//

#ifndef TRANSITION4CPP_TRANSITION_H
#define TRANSITION4CPP_TRANSITION_H


#include "Object.h"
#include "State.h"
#include "Condition.h"

class Transition : public Object {
public:
    typedef void (*callbackFunc)(const EventData *);

public:
    Transition(const string, State*, State*);
    bool execute(EventData &); // TODO：是设计成指针更好还是引用更好
    void addBeforeCallback(const callbackFunc);
    void addAfterCallback(const callbackFunc);
    void addPrepareCallback(const callbackFunc);
    string getName();

private:
    void changeState(EventData &);

private:
    string name;
    State *source;
    State *dest;
    vector<Condition> conditionList;
    vector<callbackFunc> beforeFuncList;
    vector<callbackFunc> afterFuncList;
    vector<callbackFunc> prepareFuncList;
};
#endif //TRANSITION4CPP_TRANSITION_H
