//
// Created by dendy on 19-7-3.
//
#ifndef TRANSITION4CPP_EVENTDATA_H
#define TRANSITION4CPP_EVENTDATA_H

#include <iostream>
#include <vector>

#include "Object.h"
#include "Callback.h"

using std::vector;
using std::string;

using StateMachine::callbackFunc;

namespace StateMachine {
    class Machine;
    class Model;
    class Event;
    class Transition;
    class State;

    class EventData : public Object {
    public:
        EventData();

        EventData(Machine *, Model *, Event *, Transition *, State *);

        Machine *getMachine();

        void setMachine(Machine *);

        Model *getModel();

        void setModel(Model *);

        Event *getEvent();

        void setEvent(Event *);

        Transition *getTransition();

        void setTransition(Transition *);

        State *getCurrentState();

        void setCurrentState(State *);

        void setEventData(Machine *, Model *, Event *, Transition *, State *);

        string getErrorString();

        bool getResult();

    private:
        Machine *machine;
        Model *model;
        Event *event;
        Transition *transition;
        State *currentState;

        string error;
        bool result;
    };
}

#endif //TRANSITION4CPP_EVENTDATA_H
