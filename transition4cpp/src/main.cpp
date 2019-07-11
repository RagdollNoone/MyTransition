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
    transitions.push_back({"liquid", "evaporate", "gas"});
    transitions.push_back({"solid", "sublimate", "gas"});
    transitions.push_back({"gas", "ionize", "plasma"});

    Machine *machine = new Machine(lump, &states, &transitions, "solid");

    machine->addStateCallback("solid", "enter", &(Matter::enter));
    machine->addStateCallback("solid", "exit", &(Matter::exit));

    machine->addTransitionCallback("melt", "before", &(Matter::before));
    machine->addTransitionCallback("melt", "prepare", &(Matter::prepare));
    machine->addTransitionCallback("melt", "after", &(Matter::after));

    cout << "just for break" << endl;

    lump->trigger("melt");

    cout << "--------------------------" << endl;

    lump->trigger("sublimate");

    return 0;
}