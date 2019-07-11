//
// Created by dendy on 19-7-4.
//

#include "Model.h"
using namespace StateMachine;
using std::string;
using std::cout;
using std::endl;

Model::
Model(string modelName) {
    this->modelName = modelName;
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
        this->machine->trigger(this, stateName, triggerName);
    } else {
        cout << "Model::trigger() machine point is NULL" << endl;
    }
}