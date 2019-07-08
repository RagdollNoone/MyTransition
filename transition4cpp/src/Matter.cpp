//
// Created by dendy on 2019-07-08.
//

#include "Matter.h"

void Matter::
enter(EventData *eventData) {
    cout << "enter" << endl;
}


void Matter::
exit(EventData *eventData) {
    cout << "exit" << endl;

}

void Matter::
before(EventData *eventData) {
    cout << "before" << endl;
}

void Matter::
prepare(EventData *eventData) {
    cout << "prepare" << endl;
}

void Matter::
after(EventData *eventData) {
    cout << "after" << endl;
}