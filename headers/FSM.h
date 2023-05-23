#ifndef FSM_H
#define FSM_H

#include<iostream>
#include<fstream>
#include<string>
#include<map>

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
    //variables map
    map<string, string> vars;
    //states
    map<char, State *> states;
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
    void setVar(const string& key, const string& value);
    string getVar(const string& key);
    void setState(char key, State* value);
    State* getState(char key);
    void executer();
};

#endif