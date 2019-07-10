//
// Created by dendy on 19-7-4.
//
#ifndef TRANSITION4CPP_EVENT_H
#define TRANSITION4CPP_EVENT_H

#include "Object.h"
#include "Transition.h"
#include "Model.h"
#include "State.h"

#include <string>
#include <vector>

class Machine;
class Model;
class Transition;

using namespace std;

namespace StateMachine {
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
