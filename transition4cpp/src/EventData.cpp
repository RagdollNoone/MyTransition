//
// Created by dendy on 19-7-3.
//

#include "EventData.h"

EventData::
EventData(Machine *machine, Model *model, Event *event, State *state) {
    this->machine = machine;
    this->model = model;
    this->event = event;
    this->state = state;
}

void EventData::
update() {

}

Machine* EventData::
getMachine() {
    return this->machine;
}

Model* EventData::
getModel() {
    return this->model;
}

Event* EventData::
getEvent() {
    return this->event;
}

State* EventData::
getState() {
    return this->state;
}

string EventData::
getErrorString() {
    return this->error;
}

bool EventData::
getResult() {
    return this->result;
}
