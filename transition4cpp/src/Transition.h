//
// Created by dendy on 19-7-3.
//
#ifndef TRANSITION4CPP_TRANSITION_H
#define TRANSITION4CPP_TRANSITION_H

#include <iostream>
#include <vector>

#include "Object.h"
#include "EventData.h"
#include "Callback.h"
#include "State.h"

using std::string;
using std::vector;
using StateMachine::callbackFunc;

namespace StateMachine {
    class Condition;
    class EventData;

    class Transition : public Object {

    public:
        Transition(const string, State *, State *);

        void fillCallback(EventData *);

        void addBeforeCallback(callbackFunc);

        void addAfterCallback(callbackFunc);

        void addPrepareCallback(callbackFunc);

        string getTriggerName();

        string getSrcName();

        string getDstName();

        State *getSrcState();

        State *getDstState();


        void changeTransititon(State *, State *);

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
