//
// Created by dendy on 19-7-3.
//

#ifndef TRANSITION4CPP_EVENTDATA_H
#define TRANSITION4CPP_EVENTDATA_H

#include "Object.h"
#include "State.h"
#include "Model.h"
#include "Machine.h"
#include "Event.h"

class EventData : public Object {
public:
    EventData(Machine *, Model *, Event *, State *);
    void update();

    Machine* getMachine();
    Model* getModel();
    Event* getEvent();
    State* getState();

    string getErrorString();
    bool getResult();

private:
    Machine *machine;
    Model *model;
    Event *event;
    State *state;

    string error;
    bool result;
};

#endif //TRANSITION4CPP_EVENTDATA_H
