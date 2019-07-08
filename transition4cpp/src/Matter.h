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

    void enter(EventData *);
    void exit(EventData *);

    void before(EventData *);
    void after(EventData *);
    void prepare(EventData *);
};

#endif //TRANSITION4CPP_MATTER_H
