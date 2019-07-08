//
// Created by dendy on 19-7-4.
//

#include "Event.h"

Event::
Event(string name, Machine *machine, Model *model) {
    this->name = name;
    this->machine = machine;
    this->model = model;
}

void Event::
addTransition(Transition *transition) {
    this->transitionList.push_back(transition);
}

bool Event::
trigger() {
    return true;
}

void Event::
addCallback(string funcName, Transition::callbackFunc callback) {
    vector<Transition *>::iterator it = transitionList.begin();
    for (; it != transitionList.end(); ++it) {
        if ((*it)->getName() == model->getCurrentState()->getName()) {
            if (funcName == "before") {
                (*it)->addBeforeCallback(callback);
            } else if (funcName == "after") {
                (*it)->addAfterCallback(callback);
            } else if (funcName == "prepare") {
                (*it)->addPrepareCallback(callback);
            } else {

            }
        }
    }
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