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
#include "Model.h"
#include "Callback.h"
#include "EventData.h"

//class Transition;
namespace StateMachine {
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

        bool findTransition(string, Event *&, Transition *&);

        void addTransition(vector<string> *);

        void addTransitions(vector<vector<string>> *);

        bool canTrigger(Transition *, string);

        bool canTrigger(string, string, State *&);

        void trigger(Model *, string, string);

        void addStateCallback(string, string, callbackFunc);

        void addTransitionCallback(string, string, callbackFunc);

        bool setState(Model *, EventData *);

        bool setState(Model *, string);

        string getCurrentStateName();

    private:
        void _addModel(Model *);

        void _addEvent(Event *);

        bool _setState(Model *, State *);

        Event *getEvent(string name);

        State *getState(string name);

        EventData *getParam();

        void process(EventData *);

    private:
        vector<Model *> modelList;
        vector<Event *> eventList;
        vector<State *> stateList;

        string initStateName;

        EventData *param;
    };
}

#endif //TRANSITION4CPP_MACHINE_H
