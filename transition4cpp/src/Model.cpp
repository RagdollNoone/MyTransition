//
// Created by dendy on 19-7-4.
//

#include "Model.h"

Model::
Model() {
    this->destName = string();
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
trigger(string triggerName) {
    if (NULL != machine) {
        string stateName = getCurrentStateName();

        vector<string[3]>::iterator it = eventList.begin();
        for (; it != eventList.end(); ++it) {
            if (stateName == (*it)[0] && triggerName == (*it)[1]) {
                destName = (*it)[2];
            }
        }

        if (destName.empty()) {
            machine->trigger(this, stateName, triggerName, destName);
        } else {
            // TODO: 输出出错日志
        }
    }
}