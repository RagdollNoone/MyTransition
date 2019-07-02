//
// Created by dendy on 19-7-2.
//

#ifndef TRANSITION4CPP_STATE_H
#define TRANSITION4CPP_STATE_H

#include <stdlib.h>
#include "Object.h"
#include "Machine.h"

class State : public Object{
public:
    typedef void *(enterFunc)(void);
    typedef void *(exitFunc)(void);

public:
    State(Machine machine);
    void addEnterCallback(enterFunc *enter);
    void addExitCallback(exitFunc *exit);

private:
    void onEnter();
    void onExit();

private:
    Machine machine;
    enterFunc enter;
    exitFunc exit;

};
#endif //TRANSITION4CPP_STATE_H
