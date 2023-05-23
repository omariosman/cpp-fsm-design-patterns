#ifndef JMPACTION_H
#define JMPACTION_H

#include<iostream>
#include<fstream>
#include<string>
#include<vector>

#include "FSM.h"
#include "Action.h"
#include "Transition.h"
using namespace std;

// Forward declaration of the State class
class State;

class FSM;

class Action;

class JMPAction: public Action {
public:
    JMPAction(FSM *_fsm, string _name, vector<string> _operands);
    
    string getName();
    void setName(string _name);
    void setFSM(FSM *_fsm);
    char executer();
    bool canReachDestination(char, char, vector<Transition>);
    ~JMPAction() = default;
};

#endif JMPACTION_H