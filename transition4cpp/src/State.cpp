//
// Created by dendy on 19-7-2.
//

#include "State.h"

State::
State(const string name) {
    this->name = name;
}

void State::
addEnterCallback(const callbackFunc enter) {
    this->enterFunList.push_back(enter);
}

void State::
addExitCallback(const callbackFunc exit) {
    this->exitFunList.push_back(exit);
}

string State::
getName() {
    return name;
}

void State::
onEnter() {

}

void State::
onExit() {

}