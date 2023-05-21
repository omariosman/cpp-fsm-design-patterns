#include<iostream>
#include<fstream>
#include<string>
#include<vector>

#include "FSM.h"
#include "Action.h"
#include "State.h"

int main() {
    string stateName = "a";
    //Action(FSM *_fsm, string _name, vector<string> _operands);
    State *st = new State(stateName);
    FSM *fsm = new FSM(st);
    string actionName = "AddMul";
    vector<string> operands = {"x", "x", "+", "1"};
    Action AddMul(fsm, actionName, operands);
    fsm->executer();
   
}

