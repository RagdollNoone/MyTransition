//
// Created by dendy on 19-7-3.
//

#include "Transition.h"


Transition::
Transition(const string name, State *source,  State *dest) {
    this->name = name;
    this->source = source;
    this->dest = dest;
}