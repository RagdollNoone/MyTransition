//
// Created by dendy on 19-7-3.
//
#pragma once

#ifndef TRANSITION4CPP_EVENTDATA_H
#define TRANSITION4CPP_EVENTDATA_H

#include "Object.h"
#include "Callback.h"

#include <string>
#include <vector>

class Machine;
class Model;
class Event;
class Transition;
class State;

class Condition;

using namespace std;

namespace StateMachine {
    class EventData : public Object {
    public:
        EventData();

        EventData(Machine *, Model *, Event *, Transition *, State *, State *);

        Machine *getMachine();

        void setMachine(Machine *);

        Model *getModel();

        void setModel(Model *);

        Event *getEvent();

        void setEvent(Event *);

        Transition *getTransition();

        void setTransition(Transition *);

        State *getSrcState();

        void setSrcState(State *);

        State *getDstState();

        void setDstState(State *);

        void setEventData(Machine *, Model *, Event *, Transition *, State *, State *);

        void clearCallback();

        void setPrepare(vector<callbackFunc> *);

        void setCondition(vector<Condition *> *);

        void setBefore(vector<callbackFunc> *);

        void setAfter(vector<callbackFunc> *);

        void setEnter(vector<callbackFunc> *);

        void setExit(vector<callbackFunc> *);

        string getErrorString();

        bool getResult();

    private:
        Machine *machine;
        Model *model;
        Event *event;
        Transition *transition;
        State *src;
        State *dst;

        vector<callbackFunc> *afterFuncList;
        vector<Condition *> *conditionList;
        vector<callbackFunc> *beforeFuncList;
        vector<callbackFunc> *prepareFuncList;

        vector<callbackFunc> *enterFunList;
        vector<callbackFunc> *exitFunList;

        string error;
        bool result;
    };
}

#endif //TRANSITION4CPP_EVENTDATA_H
