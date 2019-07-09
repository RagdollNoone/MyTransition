//
// Created by dendy on 19-7-4.
//

#include "Event.h"

Event::
Event(string name, Machine *machine) {
    this->name = name;
    this->machine = machine;
}

Transition* Event::
findTransition(string transition){
    vector<Transition *>::iterator it = transitionList.begin();
    for (; it != transitionList.end(); ++it) {
        if ((*it)->getTriggerName() == transition) {
            return (*it);
        }
    }

    return NULL;
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