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
    char name;
    vector<Action *> actionsList;
public:
    State();
    State(char _name);
    char getName();
    void setName(char _name);
    void setActionsList(vector<Action *> _actionsList);
    vector<Action *> getActionsList();
    // polymorphic
    void executer();
};

#endif