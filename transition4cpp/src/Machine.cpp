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

bool Machine::
findTransition(string transitionName, Event *&event, Transition *&transition) {
    vector<Event *>::iterator it = eventList.begin();

    for (; it != eventList.end(); ++it) {
        if ((*it)->findTransition(transitionName, transition)) {
            event = (*it);
            return true;
        }
    }

    return false;
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

    Event *refEvent = NULL;
    Transition *refTransition = NULL;

    if (findTransition((*transition)[1], refEvent, refTransition)) {
        refTransition->changeTransititon(src, dest);
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

bool Machine::
canTrigger(string srcName, string triggerName, State *&dst) {
    Event *event = NULL;
    Transition *transition = NULL;

    if (findTransition(triggerName, event, transition)) {
        if (transition->getSrcName() == srcName) {
            return true;
        } else {
            return false;
        }
    }
}

bool Machine::
canTrigger(Transition *transition, string srcName) {
    if (transition->getSrcName() == srcName) {
        return true;
    } else {
        return false;
    }
}

EventData* Machine::
getParam() {
    if (NULL == param) {
        param = new EventData();
    }

    return param;
}

void Machine::
trigger(Model *model, string srcName, string triggerName) {
    State *src = model->getCurrentState();
    State *dst = NULL;
    Event *refEvent = NULL;
    Transition *refTransition = NULL;

    if (findTransition(triggerName, refEvent, refTransition)) {
        if (canTrigger(refTransition, srcName)) {
            // fill EventData
            EventData *eventData = getParam();
            eventData->setEventData(this, model, refEvent, refTransition, src, dst);
            refTransition->fillCallback(eventData);
            src->fillCallback(0, eventData);
            dst->fillCallback(1, eventData);

            // do Trigger
            setState(model, eventData);

        } else {
            // error
        }
    }
}

bool Machine::
setState(Model *model, EventData *eventData) {
    _setState(model, eventData->getDstState());

//    vector<State::callbackFunc >::iterator enter = eventData->get

    return true;
}

bool Machine::
setState(Model *model, string initState) {
    State *dst = getState(initState);
    if (NULL == dst) return false;

    return _setState(model, dst);
}


bool Machine::
_setState(Model *model, State *dst) {
    model->setCurrentState(dst);
    return true;
}

void Machine::
addStateCallback(string stateName, string callbackName, State::callbackFunc callback) {
    if (callbackName == "enter") {
        getState(stateName)->addEnterCallback(callback);
    } else if (callbackName == "exit") {
        getState(stateName)->addExitCallback(callback);
    } else {

    }
}

void Machine::
addTransitionCallback(string transitionName, string callbackName, Transition::callbackFunc callback) {
    Event *event = NULL;
    Transition *transition = NULL;

    if (callbackName == "before") {
        if (findTransition(transitionName, event, transition)) {
            transition->addBeforeCallback(callback);
        }
    } else if (callbackName == "prepare") {
        if (findTransition(transitionName, event, transition)) {
            transition->addPrepareCallback(callback);
        }
    } else if (callbackName == "after") {
        if (findTransition(transitionName, event, transition)) {
            transition->addAfterCallback(callback);
        }
    } else {

    }
}