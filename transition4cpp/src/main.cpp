#include <iostream>
#include "Matter.h"
#include "Machine.h"

using StateMachine::Machine;

using std::string;
using std::vector;
using std::cout;
using std::endl;

int main() {
    Model *lump = new Matter("lump");

    vector<string> states = {"solid", "liquid", "gas", "plasma"};

    vector<vector<string>> transitions;
    transitions.push_back({"solid", "melt", "liquid"});
    transitions.push_back({"liquid", "vaporization", "gas"});
    transitions.push_back({"solid", "sublimate", "gas"});
    transitions.push_back({"gas", "ionize", "plasma"});

    Machine *machine = new Machine(lump, &states, &transitions, "solid");

    machine->addStateCallback("liquid", "enter", &(Matter::enter));
    machine->addStateCallback("solid", "exit", &(Matter::exit));

    machine->addTransitionCallback("melt", "before", &(Matter::before));
    machine->addTransitionCallback("melt", "prepare", &(Matter::prepare));
    machine->addTransitionCallback("melt", "after", &(Matter::after));

    lump->trigger("melt");
    cout << "current state is " << lump->getCurrentStateName() << endl;

    lump->trigger("vaporization");
    cout << "current state is " << lump->getCurrentStateName() << endl;

    return 0;
}