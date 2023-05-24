#ifndef ADDMUL_H
#define ADDMUL_H

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

class AddMulAction: public Action {
public:
    AddMulAction(FSM *_fsm, string _name, vector<string> _operands);
    bool isNumeric(const string& str);
    string getName();
    void setName(string _name);
    void setFSM(FSM *_fsm);
    
    void executer();
    ~AddMulAction() = default;
};

#endif 