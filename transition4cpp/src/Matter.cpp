//
// Created by dendy on 2019-07-08.
//

#include "Matter.h"
using namespace StateMachine;
using std::cout;
using std::endl;

void Matter::
enter(EventData *eventData) {
    cout << "Matter::enter" << endl;
}

void Matter::
exit(EventData *eventData) {
    cout << "Matter::exit" << endl;

}

void Matter::
before(EventData *eventData) {
    cout << "Matter::before" << endl;
}

void Matter::
prepare(EventData *eventData) {
    cout << "Matter::prepare" << endl;
}

void Matter::
after(EventData *eventData) {
    cout << "Matter::after" << endl;
}