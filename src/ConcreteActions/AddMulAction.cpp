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
    string var;
    string term1;
    string term2;
    string sign;
    try {
        var = operands[0];
        term1 = operands[1];
        sign = operands[2];
        term2 = operands[3];
    } catch (const exception& e) {
        // Handle and report the exception
        cout << "Something went wrong while reading values from the operands: " << e.what() << endl;
        return;
    }

    int op1_int = 0;
    int op2_int = 0;
    try {
        term1 = fsm->getVar(term1);
        term2 = fsm->getVar(term2);
    } catch (const exception& e) {
        // Handle and report the exception
        cout << "Something went wrong while reading variables form the machine: " << e.what() << endl;
        return;
    }

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

    int result;
    try {
        result = sign == "+" ? op1_int + op2_int : op1_int * op2_int;
    } catch (const exception& e) {
        // Handle and report the exception
        cout << "Something went wrong while doing the plus/multiply operaation: " << e.what() << endl;
        return;
    }

    string result_str;
    try {
        result_str = to_string(result);
    } catch (const exception& e) {
        // Handle and report the exception
        cout << "Something went wrong while convrting result to string: " << e.what() << endl;
        return;
    }

    try {
        fsm->setVar(var, result_str);
    } catch (const exception& e) {
        // Handle and report the exception
        cout << "Something went wrong while setting result variable in the machine vars map: " << e.what() << endl;
        return;
    }
    
    
}



