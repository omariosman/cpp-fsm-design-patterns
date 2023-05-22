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


char PrintAction::executer() {
    cout << "PrintAction executer\n";
    //check if the operand exists in the FSM map
    //if found:
        // print the value
    //else
        // print the operand as it is
    /*
    if () {

    } else {

    }
    */
cout<< operands[0]<<endl;

    
}



