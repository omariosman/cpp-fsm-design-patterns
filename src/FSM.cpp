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

void FSM::setTransitionsTable(vector<Transition> _transitionsTable) {
    transitionsTable = _transitionsTable;
}

vector<Transition> FSM::getTransitionsTable(){
    return transitionsTable;
}

State* FSM::getCurrentState(){
    return currentState;
}

void FSM::executer() {
    this->currentState->executer();
}

