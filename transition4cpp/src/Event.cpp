//
// Created by dendy on 19-7-4.
//

#include "Event.h"

Event::
Event(string name, Machine *machine) {
    this->name = name;
    this->machine = machine;
}

void Event::
addTransition(Transition *transition) {
    this->transitionList.push_back(transition);
}

bool Event::
trigger() {
    return true;
}

string Event::
getName() {
    return name;
}

bool Event::
_trigger() {
    return true;
}

bool Event::
process(EventData *) {
    return true;
}