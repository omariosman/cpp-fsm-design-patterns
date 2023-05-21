#ifndef ACTION_H
#define ACTION_H

#include<iostream>
#include<fstream>
#include<string>
#include<vector>

#include "FSM.h"

using namespace std;

// Forward declaration of the State class
class State;

class FSM;

class Action {
private:
    // We need to make composition for FSM in Action so that
    // we can setCurrentState inside wait method after 
    // getting user input
    FSM *fsm; //context
    string name;
    // Three operands can be converted to a vector of operand
    // Use builder pattern to generate relevant operands for every action
    // We may have two main types of actions:
        // - Actions with zero operands
        // - Actions with one operand
        // - Actions with four operands
    // Action names:
        // - AddMul 
        // - PRINT
        // - JMP
        // - sleep
        // - wait
        // - end
    vector<string> operands;
    /*
        string operand1;
        string operand2;
        string operand3;
    */


public:
    Action(FSM *_fsm, string _name, vector<string> _operands);
    string getName();
    void setName(string _name);
    void setFSM(FSM *_fsm);
    // polymorphic
    void executer();
};

#endif ACTION_H