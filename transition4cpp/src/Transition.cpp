//
// Created by dendy on 19-7-3.
//

#include "Transition.h"
using namespace StateMachine;
using std::string;

Transition::
Transition(const string name, State *source,  State *dest) {
    this->name = name;
    this->src = source;
    this->dst = dest;
}

void Transition::
fillCallback(EventData *eventData){
    eventData->setPrepare(&(this->prepareFuncList));
    eventData->setCondition(&(this->conditionList));
    eventData->setBefore(&(this->beforeFuncList));
    eventData->setAfter(&(this->afterFuncList));
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
    return src->getName();
}

string Transition::
getDstName() {
    return dst->getName();
}

State* Transition::
getSrcState() {
    return src;
}

State* Transition::
getDstState() {
    return dst;
}

void Transition::
changeTransititon(State *srcState, State *destState) {
    if (NULL != srcState) {
        src = srcState;
    }

    if (NULL != destState) {
        dst = destState;
    }
}
