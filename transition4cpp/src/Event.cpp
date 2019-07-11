//
// Created by dendy on 19-7-4.
//

#include "Event.h"
using namespace StateMachine;
using std::string;
using std::vector;

Event::
Event(string name) {
    this->name = name;
}

bool Event::
findTransition(string transitionName, Transition *&transition){
    vector<Transition *>::iterator it = transitionList.begin();
    for (; it != transitionList.end(); ++it) {
        if ((*it)->getTriggerName() == transitionName) {
            transition = (*it);
            return true;
        }
    }

    return false;
}

void Event::
addTransition(Transition *transition) {
    this->transitionList.push_back(transition);
}

string Event::
getName() {
    return this->name;
}

