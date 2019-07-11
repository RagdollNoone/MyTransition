//
// Created by dendy on 19-7-11.
//

#ifndef TRANSITION4CPP_UTILITY_H
#define TRANSITION4CPP_UTILITY_H
#include "Callback.h"

namespace StateMachine {
    static void callback(callbackFunc callback, EventData *eventData) {
        callback(eventData);
    }
}

#endif //TRANSITION4CPP_UTILITY_H
