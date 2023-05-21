#ifndef FSM_H
#define FSM_H

#include<iostream>
#include<fstream>
#include<string>

#include "State.h";

using namespace std;

class State;

class FSM {
private:
    string name;
    string fileName;
    ifstream fileDescriptor;
    State* currentState;
public:
    FSM(State *_initialState);
    string getName();
    void setName(string _name);
    string getFileName();
    void setFileName(string _name);
    // ifstream getFileDescriptor();
    // void setFileDescriptor(ifstream _name);
    State* getCurrentState();
    void setCurrentState(State* _state);
    void executer();
};

#endif FSM_H