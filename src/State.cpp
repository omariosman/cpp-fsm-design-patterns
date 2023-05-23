#include "../headers/State.h"

State::State(){
}


State::State(char _name){
    name = _name;
}

char State::getName() {
    return name;
}

void State::setName(char _name) {
    name = _name;
}

void State::setActionsList(vector<Action *> _actionsList){
    actionsList = _actionsList;
}

vector<Action *> State::getActionsList(){
    return actionsList;
}



void State::executer() {
    //cout << "fsm executer\n";
    //call list of acitons executers
    for (auto action: actionsList) {
        action->executer();
    }
}