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
    typedef void (*beforeFunc)(const EventData *);
    typedef void (*afterFunc)(const EventData *);
    typedef void (*prepareFunc)(const EventData *);

public:
    Transition(const string, State*, State*);
    bool execute(EventData &); // TODO：是设计成指针更好还是引用更好
    void addBeforeCallback(const beforeFunc);
    void addAfterCallback(const afterFunc);
    void addPrepareCallback(const prepareFunc);

private:
    void changeState(EventData &);

private:
    string name;
    State *source;
    State *dest;
    vector<Condition> conditionList;
    vector<beforeFunc> beforeFuncList;
    vector<afterFunc> afterFuncList;
    vector<prepareFunc> prepareFuncList;
};
#endif //TRANSITION4CPP_TRANSITION_H
