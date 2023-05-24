#include "../../headers/ConcreteActions/EndAction.h"
#include "../../headers/Transition/Transition.h"
#include "../../headers/State/State.h"
#include<tuple>

EndAction::EndAction(FSM *_fsm, string _name, vector<string> _operands)
     : Action(_fsm, _name, _operands) {
}

string EndAction::getName() {
    return name;
}

void EndAction::setName(string _name) {
    name = _name;
}

void EndAction::setFSM(FSM *_fsm) {
    fsm = _fsm;
}


void EndAction::executer() {
    //cout << "EndAction executer\n";
    try {
        exit(0);
    } catch (const exception& e) {
        // Handle and report the exception
        cout << "Something went wrong while terminating the program: " << e.what() << endl;
        return;
    }
    
    
}



