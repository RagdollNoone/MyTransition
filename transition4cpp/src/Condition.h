//
// Created by dendy on 19-7-3.
//
#ifndef TRANSITION4CPP_CONDITION_H
#define TRANSITION4CPP_CONDITION_H

#include "Object.h"

namespace StateMachine {
    class EventData;

    class Condition : public Object {
    public:
        virtual bool check();
    };
}
#endif //TRANSITION4CPP_CONDITION_H
