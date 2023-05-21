#include "Action.h"

Action::Action(FSM *_fsm, string _name, vector<string> _operands)
     : fsm(_fsm), name(_name), operands(_operands)  {

}

void Action::executer() {
    cout << "Action executer\n";
}

string Action::getName() {
    return name;
}

void Action::setName(string _name) {
    name = _name;
}

void Action::setFSM(FSM *_fsm) {
    fsm = _fsm;
}

