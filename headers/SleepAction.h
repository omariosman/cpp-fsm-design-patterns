#ifndef SLEEPACTION_H
#define SLEEPACTION_H

#include<iostream>
#include<fstream>
#include<string>
#include<vector>

#include "FSM.h"
#include "Action.h"

using namespace std;

// Forward declaration of the State class
class State;

class FSM;

class Action;

class SleepAction: public Action {
public:
    SleepAction(FSM *_fsm, string _name, vector<string> _operands);
    
    string getName();
    void setName(string _name);
    void setFSM(FSM *_fsm);
    
    char executer();
    ~SleepAction() = default;
};

#endif SLEEPACTION_H