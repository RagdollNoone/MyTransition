//
// Created by dendy on 19-7-2.
//
#ifndef TRANSITION4CPP_STATE_H
#define TRANSITION4CPP_STATE_H

#include "Object.h"
#include <string>
#include <vector>

class EventData;

using namespace std;

class State : public Object{
public:
    typedef void (*callbackFunc)(const EventData *);

public:
    State(const string);
    void addEnterCallback(const callbackFunc);
    void addExitCallback(const callbackFunc);
    string getName();

private:
    void onEnter();
    void onExit();

private:
    string name;
    vector<callbackFunc> enterFunList;
    vector<callbackFunc> exitFunList;
};
#endif //TRANSITION4CPP_STATE_H
