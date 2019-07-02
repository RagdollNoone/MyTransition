//
// Created by dendy on 19-7-2.
//

#include "State.h"

State::
State(Machine machine) {
    this->machine = machine;
}

void State::
addEnterCallback(enterFunc *enter) {

}

void State::
addExitCallback(exitFunc *exit) {

}

void State::
onEnter() {

}

void State::onExit() {}