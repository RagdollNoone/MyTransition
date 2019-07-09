//
// Created by dendy on 19-7-2.
//

#include "State.h"

State::
State(string name) {
    this->name = name;
}

void State::
addEnterCallback(callbackFunc enter) {
    this->enterFunList.push_back(enter);
}

void State::
addExitCallback(callbackFunc exit) {
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