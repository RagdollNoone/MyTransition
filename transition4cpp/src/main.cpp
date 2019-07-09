#include <iostream>
#include "Matter.h"

int main() {
    Model *lump = new Matter("lump");

    vector<string> states = {"solid", "liquid", "gas", "plasma"};

    vector<vector<string>> transitions;
    transitions.push_back({"solid", "melt", "liquid"});
    transitions.push_back({"liquid", "evaporate", "gas"});
    transitions.push_back({"solid", "sublimate", "gas"});
    transitions.push_back({"gas", "ionize", "plasma"});

    Machine *machine = new Machine(lump, &states, &transitions, "solid");

    cout << "just for break" << endl;

    return 0;
}