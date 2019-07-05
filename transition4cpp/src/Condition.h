//
// Created by dendy on 19-7-3.
//

#ifndef TRANSITION4CPP_CONDITION_H
#define TRANSITION4CPP_CONDITION_H

#include "Object.h"

class EventData;

class Condition : public Object {
public:
    typedef bool (*checkFunc)(EventData *);

public:
    Condition(checkFunc);
    bool check();

private:
    checkFunc callback;


};
#endif //TRANSITION4CPP_CONDITION_H
