//
// Created by dendy on 19-7-2.
//

#include "State.h"

State::
State(const string name) {
    this->name = name;
}

void State::
addEnterCallback(const enterFunc enter) {
    this->enterFunList.push_back(enter);
}

void State::
addExitCallback(const exitFunc exit) {
    this->exitFunList.push_back(exit);
}

void State::
onEnter() {

}

void State::
onExit() {

}