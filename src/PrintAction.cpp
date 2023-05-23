#include "../headers/PrintAction.h"
#include "../headers/Transition.h"
#include "../headers/State.h"
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
    cout << fsm->getVar(operands[0]);
}
