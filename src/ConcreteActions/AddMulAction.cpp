#include "../headers/ConcreteActions/AddMulAction.h"
#include "../headers/Transition/Transition.h"
#include "../headers/State/State.h"
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

bool AddMulAction::isNumeric(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}


void AddMulAction::executer() {
    //cout << "AddMulAction executer\n";
    string var = operands[0];
    string term1 = operands[1];
    string term2 = operands[3];
    term1 = fsm->getVar(term1);
    term2 = fsm->getVar(term2);
    int op1_int = 0;
    int op2_int = 0;
    //Exception handling
    try {
        op1_int = stoi(term1);
        op2_int = stoi(term2);
    } catch (const std::invalid_argument& e) {
        cerr << "Invalid argument: " << e.what() << endl;
        return;
    } catch (const std::out_of_range& e) {
        cerr << "Out of range: " << e.what() << endl;
        return;
    }

    int result = operands[2] == "+" ? op1_int + op2_int : op1_int * op2_int;
    string result_str = to_string(result);
    fsm->setVar(var, result_str);
    
}



