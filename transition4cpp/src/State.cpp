//
// Created by dendy on 19-7-2.
//

#include "State.h"
using namespace StateMachine;
using std::string;

State::
State(string name) {
    this->name = name;
}

void State::
fillCallback(int type, EventData *eventData){
    if (type == 0) {
        eventData->setEnter(&(this->enterFunList));
    } else if (type == 1) {
        eventData->setExit(&(this->exitFunList));
    } else {

    }
}

void State::
addEnterCallback(callbackFunc exit) {
    this->enterFunList.push_back(exit);
}

void State::
addExitCallback(callbackFunc exit) {
    this->exitFunList.push_back(exit);
}

string State::
getName() {
    return this->name;
}
