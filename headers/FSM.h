#ifndef FSM_H
#define FSM_H

#include<iostream>
#include<fstream>
#include<string>

#include "State.h"
#include "Transition.h"

using namespace std;
class State;
class Transition;

// Define a type alias for transitions
//using Transition = tuple<char, char, int>;

class FSM {
private:
    string name;
    string fileName;
    ifstream fileDescriptor;
    State* currentState;
    vector<Transition> transitionsTable;
public:
    FSM(State *_initialState);
    string getName();
    void setName(string _name);
    string getFileName();
    void setFileName(string _name);
    vector<Transition> getTransitionsTable();
    void setTransitionsTable(vector<Transition> _transitionsTable);
    // ifstream getFileDescriptor();
    // void setFileDescriptor(ifstream _name);
    State* getCurrentState();
    void setCurrentState(State* _state);
    void executer();
};

#endif