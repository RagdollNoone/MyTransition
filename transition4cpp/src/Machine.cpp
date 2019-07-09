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
Machine(Model *model, vector<string> *states, vector<vector<string>> *transitions, string initStateName) {
    this->initStateName = initStateName;
    this->addStates(states);
    this->addTransitions(transitions);
    this->addModel(model);
}

void Machine::
addModel(Model *model) {
    this->initModel(model);
    this->_addModel(model);
}

void Machine::
initModel(Model *model) {
    setState(model, initStateName);
    model->setMachine(this);
}

void Machine::
_addModel(Model *model) {
    modelList.push_back(model);
}

void Machine::
addStates(vector<string> *states) {
    vector<string>::iterator it = (*states).begin();

    for (; it != states->end(); ++it) {
        addState(*it);
    }
}

bool Machine::
isStateExit(string name) {
    vector<State *>::iterator it = stateList.begin();
    for (; it != stateList.end(); ++it) {
        if ((*it)->getName() == name) {
            return true;
        }
    }

    return false;
}

void Machine::
addState(string stateName) {
    if (isStateExit(stateName)) return;

    State *newState = new State(stateName);
    stateList.push_back(newState);
}

void Machine::
addTransitions(vector<vector<string>> *transitions) {
    vector<vector<string>>::iterator it = (*transitions).begin();

    for (; it != transitions->end(); ++it) {
        addTransition(&(*it));
    }
}

Transition* Machine::
findTransition(vector<string> *transition) {
    vector<Event *>::iterator it = eventList.begin();

    for (; it != eventList.end(); ++it) {
        Transition *ret = (*it)->findTransition(transition);
        if(NULL != ret)
            return ret;
    }

    return NULL;
}

void Machine::
addTransition(vector<string> *transition) {
    State *src = getState((*transition)[0]);
    State *dest = getState((*transition)[2]);

    if (NULL == src || NULL == dest) {
        // TODO: error process
        return;
    }

    Event *event = getEvent(src->getName());
    if (NULL == event) {
        event = new Event(src->getName(), this);
        this->_addEvent(event);
    }

    Transition *temp = findTransition(transition);
    if (NULL != temp) {
        temp->changeDestState(dest);
    } else {
        Transition *newTransition = new Transition((*transition)[1], src, dest);
        event->addTransition(newTransition);
    }
}

void Machine::
_addEvent(Event *event) {
    this->eventList.push_back(event);
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
trigger(Model *model, string srcName, string destName) {

}


bool Machine::
setState(Model *model, string initState) {
    State *state = getState(initState);
    if (NULL == state) return false;

    model->setCurrentState(state);
    return true;
}