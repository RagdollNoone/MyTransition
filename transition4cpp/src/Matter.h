//
// Created by dendy on 2019-07-08.
//

#ifndef TRANSITION4CPP_MATTER_H
#define TRANSITION4CPP_MATTER_H

#include "Model.h"
#include <iostream>

using namespace std;

class EventData;

class Matter : public Model {
public:
    Matter(string modelName) : Model(modelName) {};

    static void enter(EventData *);
    static void exit(EventData *);

    static void before(EventData *);
    static void after(EventData *);
    static void prepare(EventData *);
};

#endif //TRANSITION4CPP_MATTER_H
