//
// Created by dendy on 19-7-2.
//
#ifndef TRANSITION4CPP_STATE_H
#define TRANSITION4CPP_STATE_H

#include "Object.h"
#include <string>
#include <vector>

#include "EventData.h"
#include "Callback.h"

class EventData;

using namespace std;

namespace StateMachine {
    class State : public Object {

    public:
        State(string);

        void fillCallback(int, EventData *);

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
