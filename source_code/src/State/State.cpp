#include "../../headers/State/State.h"

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
    try {
        for (auto action: actionsList) {
            cout << "\nAction executing: " << action->getName() << "\n";
            action->executer();
        }
    } catch (const exception& e) {
        // Handle and report the exception
        cout << "Something went wrong while iterating over actions list in the state: " << e.what() << endl;
        return;
    }
}