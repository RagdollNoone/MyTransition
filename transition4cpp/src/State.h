//
// Created by dendy on 19-7-2.
//
#ifndef TRANSITION4CPP_STATE_H
#define TRANSITION4CPP_STATE_H

#include <iostream>
#include <vector>

#include "Object.h"
#include "Utility.h"

using std::string;
using std::vector;

namespace StateMachine {
    class EventData;

    class State : public Object {
    public:
        State(string);

        void enter(EventData *);
        void exit(EventData *);

        void addEnterCallback(callbackFunc);
        void addExitCallback(callbackFunc);

        string getName();

    private:
        string name;
        vector<callbackFunc> enterFunList;
        vector<callbackFunc> exitFunList;
    };
}
#endif //TRANSITION4CPP_STATE_H
