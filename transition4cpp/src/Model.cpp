//
// Created by dendy on 19-7-4.
//

#include "Model.h"

Model::
Model(string modelName) {
    this->destName = modelName;
}

void Model::
setCurrentState(State *state) {
    this->currentState = state;
}

State* Model::
getCurrentState() {
    return this->currentState;
}

string Model::
getCurrentStateName() {
    return currentState->getName();
}

void Model::
setMachine(Machine *machine) {
    this->machine = machine;
}

void Model::
setEventList(vector<vector<string>> *eventList) {
    vector<vector<string>>::iterator it = eventList->begin();
    for (; it != eventList->end(); ++it) {
        this->eventList.push_back(*it);
    }
}

void Model::
setStateList(vector<string> *stateList) {
    vector<string>::iterator it = stateList->begin();
    for (; it != stateList->end(); ++it) {
        this->stateList.push_back(*it);
    }
}

void Model::
addEvent(vector<string> *event) {
    this->eventList.push_back(*event);
}

void Model::
addState(string state) {
    this->stateList.push_back(state);
}

void Model::
trigger(string triggerName) {
    if (NULL != machine) {
        string stateName = getCurrentStateName();

        vector<vector<string>>::iterator it = eventList.begin();
        for (; it != eventList.end(); ++it) {
            if (stateName == (*it)[0] && triggerName == (*it)[1]) {
                destName = (*it)[2];
            }
        }

        if (!destName.empty()) {
            machine->trigger(this, stateName, triggerName, destName);
        } else {

        }
    }
}