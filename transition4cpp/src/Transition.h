//
// Created by dendy on 19-7-3.
//
#ifndef TRANSITION4CPP_TRANSITION_H
#define TRANSITION4CPP_TRANSITION_H

#include <string>
#include <vector>

#include "Object.h"
#include "State.h"
#include "Condition.h"
#include "EventData.h"

class State;
class Condition;
class EventData;

using namespace std;

namespace StateMachine {
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
