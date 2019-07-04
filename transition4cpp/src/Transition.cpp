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

}

void Transition::
addBeforeCallback(const beforeFunc callback) {
    beforeFuncList.push_back(callback);
}

void Transition::
addAfterCallback(const afterFunc callback) {
    afterFuncList.push_back(callback);
}

void Transition::
addPrepareCallback(const prepareFunc callback) {
    prepareFuncList.push_back(callback);
}


void Transition::
changeState(EventData &) {

}
