//
// Created by dendy on 19-7-4.
//

#include "Model.h"

Model::
Model() {

}

void Model::
setCurrentState(State *state) {
    this->currentState = state;
}

State* Model::
getCurrentState() {
    return this->currentState;
}