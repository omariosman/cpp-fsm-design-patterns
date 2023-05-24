#ifndef JMPACTION_H
#define JMPACTION_H

#include<iostream>
#include<fstream>
#include<string>
#include<vector>

#include "../FSM/FSM.h"
#include "../IAction/Action.h"
#include "../Transition/Transition.h"
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
    bool canReachDestination(char, char, vector<Transition *>);
    void executer();
    ~JMPAction() = default;
};

#endif