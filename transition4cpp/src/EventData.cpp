//
// Created by dendy on 19-7-3.
//

#include "EventData.h"
using namespace StateMachine;

EventData::EventData() {

}

EventData::
EventData(Machine *machine, Model *model, Event *event, Transition *transition, State *state) {
    this->machine = machine;
    this->model = model;
    this->event = event;
    this->transition = transition;
    this->currentState = state;
}

void EventData::
setEventData(Machine *machine, Model *model, Event *event,  Transition *transition, State *state) {
    setMachine(machine);
    setModel(model);
    setEvent(event);
    setTransition(transition);
    setCurrentState(state);
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
getCurrentState() {
    return this->currentState;
}

void EventData::
setCurrentState(State *state) {
    this->currentState = state;
}

bool EventData::
trigger() {
    if (NULL == transition) {
        return false;
    }

    return transition->execute(this);
}
