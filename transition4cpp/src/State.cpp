//
// Created by dendy on 19-7-2.
//

#include "State.h"
using namespace StateMachine;
using std::string;
using std::vector;

State::
State(string name) {
    this->name = name;
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

void State::
enter(EventData *eventData) {
    vector<callbackFunc>::iterator it = enterFunList.begin();
    for (; it != enterFunList.end(); ++it) {
        callback((*it), eventData);
    }
}

void State::
exit(EventData *eventData) {
    vector<callbackFunc>::iterator it = exitFunList.begin();
    for (; it != exitFunList.end(); ++it) {
        callback((*it), eventData);
    }
}