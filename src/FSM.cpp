#include "../headers/FSM.h"

FSM::FSM(State *_initialState) : currentState(_initialState) {

}

string FSM::getName() {
    return name;
}

void FSM::setName(string _name) {
    name = _name;
}

string FSM::getFileName() {
    return fileName;
}

void FSM::setFileName(string _fileName) {
    fileName = _fileName;
}
/*
ifstream FSM::getFileDescriptor() {
    return fileDescriptor;
}

void FSM::setFileDescriptor(ifstream _fileDescriptor) {
    fileDescriptor = _fileDescriptor;
}
*/
void FSM::setCurrentState(State* _currentState) {
    currentState = _currentState;
}

void FSM::setTransitionsTable(vector<Transition *> _transitionsTable) {
    transitionsTable = _transitionsTable;
}

vector<Transition *> FSM::getTransitionsTable(){
    return transitionsTable;
}

State* FSM::getCurrentState(){
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

void FSM::setState(char key, State* value) {
    states[key] = value;
}

State* FSM::getState(char key) {
    auto it = states.find(key);
    if (it != states.end()) {
        return it->second;
    } 
}

void FSM::setStates(map<char, State *> _states) {
    states = _states;
}

map<char, State *> FSM::getStates() {
    return states;
}

void FSM::executer() {
    this->currentState->executer();
}


