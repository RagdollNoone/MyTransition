//
// Created by dendy on 19-7-2.
//

#ifndef TRANSITION4CPP_STATE_H
#define TRANSITION4CPP_STATE_H

#include <stdlib.h>
#include <vector>
#include <string>
#include "Object.h"
#include "Machine.h"
#include "EventData.h"

using namespace std;

class State : public Object{
public:
    // TODO：check const位置和修饰含义的关系
    typedef void (*enterFunc)(const EventData *);
    typedef void (*exitFunc)(const EventData *);

public:
    State(const string);
    void addEnterCallback(const enterFunc);
    void addExitCallback(const exitFunc);

    // TODO：remove 操作有必要实现吗?

private:
    void onEnter();
    void onExit();

private:
    string name;
    vector<enterFunc> enterFunList;
    vector<exitFunc> exitFunList;
};
#endif //TRANSITION4CPP_STATE_H
