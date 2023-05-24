#include "../../headers/ConcreteActions/PrintAction.h"
#include "../../headers/Transition/Transition.h"
#include "../../headers/State/State.h"
#include<tuple>

PrintAction::PrintAction(FSM *_fsm, string _name, vector<string> _operands)
     : Action(_fsm, _name, _operands) {
}

string PrintAction::getName() {
    return name;
}

void PrintAction::setName(string _name) {
    name = _name;
}

void PrintAction::setFSM(FSM *_fsm) {
    fsm = _fsm;
}


void PrintAction::executer() {
    //cout << "PrintAction executer\n";
    try {
        cout << fsm->getVar(operands[0]) << "\n";
    } catch (const exception& e) {
        // Handle and report the exception
        cout << "Error occured while reading the variable value from the machine: " << e.what() << endl;
        return; 
    }
}
