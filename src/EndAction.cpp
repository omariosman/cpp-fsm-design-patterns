#include "../headers/EndAction.h"
#include "../headers/Transition.h"
#include "../headers/State.h"
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


char EndAction::executer() {
    cout << "EndAction executer\n";
    exit(0);
    
}



