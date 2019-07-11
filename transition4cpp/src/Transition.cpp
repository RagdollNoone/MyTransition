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

bool Transition::
changeTransition(State *srcState, State *destState) {
    State *oldSrc = src;
    State *oldDst = dst;

    bool ret = true;

    if (NULL == srcState) {
        ret = false;
    } else {
        src = srcState;
    }

    if (NULL == destState) {
        ret = false;
    } else {
        dst = destState;
    }

    if (!ret) {
        src = oldSrc;
        dst = oldDst;
    }

    return ret;
}

void Transition::
prepare(StateMachine::EventData *eventData) {
    vector<callbackFunc>::iterator prepare = prepareFuncList.begin();
    for (; prepare != prepareFuncList.end(); ++prepare) {
        callback((*prepare), eventData);
    }
}

bool Transition::
checkCondition(StateMachine::EventData *eventData) {
    bool ret = true;

    vector<Condition *>::iterator condition = conditionList.begin();
    for (; condition != conditionList.end(); ++condition) {
        if (!(*condition)->check()) {
            ret = false;
            break;
        }
    }

    return ret;
}


void Transition::
beforeTransition(StateMachine::EventData *eventData) {
    vector<callbackFunc>::iterator before = beforeFuncList.begin();
    for (; before != beforeFuncList.end(); ++before) {
        callback((*before), eventData);
    }
}

void Transition::
afterTransition(StateMachine::EventData *eventData) {
    vector<callbackFunc>::iterator after = afterFuncList.begin();
    for (; after != afterFuncList.end(); ++after) {
        callback((*after), eventData);
    }
}




//src->exit(eventData);
//eventData->setCurrentState(dst);
//dst->enter(eventData);





