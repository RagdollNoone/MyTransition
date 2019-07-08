//
// Created by dendy on 19-7-2.
//

#include "Machine.h"

Machine::
Machine() {

}

Machine::
Machine(Model *model) {
    this->addModel(model);
}

Machine::
Machine(Model *model, vector<string> *states, vector<string[3]> *transitions, string initStateName) {
    this->addModel(model);
    this->addStates(states);
    this->addTransitions(transitions);

    this->initStateName = initStateName;
}

void Machine::
addModel(Model *model) {
    setState(model, initStateName);
    modelList.push_back(model);
}

void Machine::
addStates(vector<string> *states) {
    vector<string>::iterator it = (*states).begin();

    for (; it != states->end(); ++it) {
        addState(*it);
    }
}

void Machine::
addState(string stateName) {
    State *newState = new State(stateName);
    stateList.push_back(newState);
}

void Machine::
addTransitions(vector<string[3]> *transitions) {
    vector<string[3]>::iterator it = (*transitions).begin();

    for (; it != transitions->end(); ++it) {
        addTransition(*it);
    }
}

void Machine::
addTransition(string transition[3]) {
    State *src = getState(transition[0]);
    State *dest = getState(transition[2]);

    if (NULL == src || NULL == dest) {
        // TODO: error process
        return;
    }

//    Transition *newTransition = new Transition(transition[1], src, dest);



}

State* Machine::
getState(string name) {
    State *ret = NULL;
    vector<State *>::iterator it = stateList.begin();

    for (; it != stateList.end(); ++it) {
        if ((*it)->getName() == name) {
            ret = *it;
        }
    }

    return ret;
}

Event* Machine::
getEvent(string name) {
    Event *ret = NULL;
    vector<Event *>::iterator it = eventList.begin();

    for(; it != eventList.end(); ++it) {
        if ((*it)->getName() == name) {
            ret = *it;
        }
    }

    return ret;
}

void Machine::
trigger(Model *, string, string, string) {

}


bool Machine::
setState(Model *, string) {
    return true;
}