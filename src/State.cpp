#include "../headers/State.h"

State::State(char _name){
    name = _name;
}

char State::getName() {
    return name;
}

void State::setName(char _name) {
    name = _name;
}

void State::setActionsList(vector<Action> _actionsList){
    actionsList = _actionsList;
}


void State::executer() {
    //call list of acitons executers
    for (auto action: actionsList) {
        cout<< "thee next state is: "<<action.executer() <<endl;
    }
}