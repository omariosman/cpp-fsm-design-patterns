#include "../headers/AddMulAction.h"
#include "../headers/Transition.h"
#include "../headers/State.h"
#include<tuple>

AddMulAction::AddMulAction(FSM *_fsm, string _name, vector<string> _operands)
     : Action(_fsm, _name, _operands) {
}

string AddMulAction::getName() {
    return name;
}

void AddMulAction::setName(string _name) {
    name = _name;
}

void AddMulAction::setFSM(FSM *_fsm) {
    fsm = _fsm;
}


char AddMulAction::executer() {
    cout << "AddMulAction executer\n";
    string var = operands[0];
    string term1 = operands[1];
    string term2 = operands[3];
    term1 = fsm->getVar(term1);
    term2 = fsm->getVar(term2);
    int op1_int = stoi(term1);
    int op2_int = stoi(term2);
    int result = operands[2] == "+" ? op1_int + op2_int : op1_int * op2_int;
    string result_str = to_string(result);
    fsm->setVar(var, result_str);
}



