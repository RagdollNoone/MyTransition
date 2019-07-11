//
// Created by dendy on 19-7-4.
//
#ifndef TRANSITION4CPP_EVENT_H
#define TRANSITION4CPP_EVENT_H

#include <iostream>
#include <vector>

#include "Object.h"
#include "Transition.h"

using std::string;
using std::vector;

namespace StateMachine {
    class Machine;

    class Event : public Object {
    public:
        Event(string, Machine *);

        bool findTransition(string, Transition *&);

        void addTransition(Transition *);

        string getName();

    private:
        Machine *machine;
        string name;
        vector<Transition *> transitionList;
    };
}
#endif //TRANSITION4CPP_EVENT_H
