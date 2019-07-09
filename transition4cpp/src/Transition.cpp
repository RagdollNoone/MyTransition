//
// Created by dendy on 19-7-3.
//

#include "Transition.h"

Transition::
Transition(const string name, State *source,  State *dest) {
    this->name = name;
    this->source = source;
    this->dest = dest;
}

bool Transition::
execute(EventData &) {
    return true;
}

void Transition::
addBeforeCallback(const callbackFunc callback) {
    beforeFuncList.push_back(callback);
}

void Transition::
addAfterCallback(const callbackFunc callback) {
    afterFuncList.push_back(callback);
}

void Transition::
addPrepareCallback(const callbackFunc callback) {
    prepareFuncList.push_back(callback);
}

string Transition::
getTriggerName() {
    return name;
}

string Transition::
getSrcName() {
    return source->getName();
}

void Transition::
changeDestState(State *destState) {
    dest = destState;
}

void Transition::
changeState(EventData &) {

}
