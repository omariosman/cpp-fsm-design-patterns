#include "../../headers/FSM/FSM.h"
#include<iostream>
#include<memory>

FSM::FSM() {

}

FSM::FSM(shared_ptr<State> _initialState) : currentState(_initialState) {

}

string FSM::getName() {
    return name;
}

void FSM::setName(string _name) {
    name = _name;
}

void FSM::setCurrentState(shared_ptr<State> _currentState) {
    currentState = _currentState;
}

void FSM::setTransitionsTable(vector<Transition *> _transitionsTable) {
    transitionsTable = _transitionsTable;
}

vector<Transition *> FSM::getTransitionsTable(){
    return transitionsTable;
}

shared_ptr<State> FSM::getCurrentState(){
    return currentState;
}

// Setter function to add or update a key-value pair in the vars map
void FSM::setVar(const string& key, const string& value) {
    vars[key] = value;
}

// Getter function to retrieve the value associated with a key in the vars map
string FSM::getVar(const string& key) {
    auto it = vars.find(key);
    if (it != vars.end()) {
        return it->second;
    } else {
        return key; 
    }
}

void FSM::setState(char key, shared_ptr<State> value) {
    states[key] = value;
}

shared_ptr<State> FSM::getState(char key) {
    auto it = states.find(key);
    if (it != states.end()) {
        return it->second;
    } 
}

void FSM::setStates(map<char, shared_ptr<State>> _states) {
    states = _states;
}

map<char, shared_ptr<State>> FSM::getStates() {
    return states;
}

void FSM::executer() {
    //cout << "fsm executer\n";
    cout << "Active State: " << this->getCurrentState()->getName() << "\n";
    try {
        this->currentState->executer();
    } catch (const exception& e) {
        // Handle and report the exception
        cout << "Something went wrong while executing the fsm: " << e.what() << endl;
        return;
    }
    
}


