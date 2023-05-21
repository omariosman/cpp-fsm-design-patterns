#ifndef STATE_H
#define STATE_H

#include<iostream>
#include<fstream>
#include<string>
#include<vector>

#include "Action.h"

using namespace std;

// Forward declaration of the Action class
class Action;

class State {
private:
    string name;
    vector<Action> actionsList;
public:
    State(string _name);
    string getName();
    void setName(string _name);
    void setActionsList(vector<Action> _actionsList);
    // polymorphic
    void executer();
};

#endif STATE_H