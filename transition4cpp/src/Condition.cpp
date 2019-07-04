//
// Created by dendy on 19-7-3.
//

#include "Condition.h"

Condition::
Condition(checkFunc callback) {
    this->callback = callback;
}

bool Condition::
check() {
    return true;
}