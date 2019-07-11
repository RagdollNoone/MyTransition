//
// Created by dendy on 19-7-3.
//
#ifndef TRANSITION4CPP_TRANSITION_H
#define TRANSITION4CPP_TRANSITION_H

#include <iostream>
#include <vector>

#include "State.h"
#include "Condition.h"
#include "Callback.h"
#include "Utility.h"

using std::string;
using std::vector;

namespace StateMachine {
    class State;

    class Transition : public Object {

    public:
        Transition(const string, State *, State *);

        void addBeforeCallback(callbackFunc);

        void addAfterCallback(callbackFunc);

        void addPrepareCallback(callbackFunc);

        string getTriggerName();

        string getSrcName();

        string getDstName();

        State *getSrcState();

        State *getDstState();

        void prepare(EventData *);
        bool checkCondition(EventData *);
        void beforeTransition(EventData *);
        void afterTransition(EventData *);

        bool changeTransition(State *, State *);

    private:
        string name;
        State *src;
        State *dst;

        vector<Condition *> conditionList;
        vector<callbackFunc> beforeFuncList;
        vector<callbackFunc> afterFuncList;
        vector<callbackFunc> prepareFuncList;
    };
}
#endif //TRANSITION4CPP_TRANSITION_H
