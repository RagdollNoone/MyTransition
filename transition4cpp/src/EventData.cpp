//
// Created by dendy on 19-7-3.
//

#include "EventData.h"

EventData::EventData() {

}

EventData::
EventData(Machine *machine, Model *model, Event *event, Transition *transition, State *src, State *dst) {
    this->machine = machine;
    this->model = model;
    this->event = event;
    this->transition = transition;
    this->src = src;
    this->dst = dst;
}

void EventData::
setEventData(Machine *machine, Model *model, Event *event,  Transition *transition, State *src, State *dst) {
    setMachine(machine);
    setModel(model);
    setEvent(event);
    setTransition(transition);
    setSrcState(src);
    setDstState(dst);

    clearCallback();
}

Machine* EventData::
getMachine() {
    return this->machine;
}

void EventData::
setMachine(Machine *machine) {
    this->machine = machine;
}

Model* EventData::
getModel() {
    return this->model;
}

void EventData::
setModel(Model *model) {
    this->model = model;
}

Event* EventData::
getEvent() {
    return this->event;
}

void EventData::
setEvent(Event *event) {
    this->event = event;
}

Transition* EventData::
getTransition() {
    return this->transition;
}

void EventData::
setTransition(Transition *transition) {
    this->transition = transition;
}

State* EventData::
getSrcState() {
    return this->src;
}

void EventData::
setSrcState(State *src) {
    this->src = src;
}

State* EventData::
getDstState() {
    return this->dst;
}

void EventData::
setDstState(State *dst) {
    this->dst = dst;
}

string EventData::
getErrorString() {
    return this->error;
}

bool EventData::
getResult() {
    return this->result;
}

void EventData::
clearCallback() {
    conditionList = NULL;
    beforeFuncList = NULL;
    afterFuncList = NULL;
    prepareFuncList = NULL;

    enterFunList = NULL;
    exitFunList = NULL;
}

void EventData::
setPrepare(vector<Transition::callbackFunc> *prepareFuncList) {
    this->prepareFuncList = prepareFuncList;
}

void EventData::
setCondition(vector<Condition *> *conditionList) {
    this->conditionList = conditionList;
}

void EventData::
setBefore(vector<Transition::callbackFunc> *beforeFuncList) {
    this->beforeFuncList = beforeFuncList;
}

void EventData::
setAfter(vector<Transition::callbackFunc> *afterFuncList) {
    this->afterFuncList = afterFuncList;
}

void EventData::
setEnter(vector<State::callbackFunc> *enterFunList) {
    this->enterFunList = enterFunList;
}

void EventData::
setExit(vector<State::callbackFunc> *exitFunList) {
    this->afterFuncList = exitFunList;
}
