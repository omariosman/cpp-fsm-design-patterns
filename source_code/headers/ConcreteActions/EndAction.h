#ifndef ENDACTION_H
#define ENDACTION_H

#include<iostream>
#include<fstream>
#include<string>
#include<vector>

#include "../FSM/FSM.h"
#include "../IAction/Action.h"

using namespace std;

// Forward declaration of the State class
class State;

class FSM;

class Action;

class EndAction: public Action {
public:
    EndAction(FSM *_fsm, string _name, vector<string> _operands);
    
    string getName();
    void setName(string _name);
    void setFSM(FSM *_fsm);
    
    void executer();
    ~EndAction() = default;
};

#endif