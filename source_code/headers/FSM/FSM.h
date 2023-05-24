#ifndef FSM_H
#define FSM_H

#include<iostream>
#include<fstream>
#include<string>
#include<map>

#include "../State/State.h"
#include "../Transition/Transition.h"

using namespace std;
class State;
class Transition;

// Define a type alias for transitions
//using Transition = tuple<char, char, int>;

class FSM {
private:
    string name;
    ifstream fileDescriptor;
    shared_ptr<State> currentState;
    vector<Transition *> transitionsTable;
    //variables map
    map<string, string> vars;
    //states
    map<char, shared_ptr<State>> states;
public:    
    FSM();
    FSM(shared_ptr<State>_initialState);
    string getName();
    void setName(string _name);
    vector<Transition *> getTransitionsTable();
    void setTransitionsTable(vector<Transition *> _transitionsTable);
    // ifstream getFileDescriptor();
    // void setFileDescriptor(ifstream _name);
    shared_ptr<State> getCurrentState();
    void setCurrentState(shared_ptr<State> _state);
    void setVar(const string& key, const string& value);
    string getVar(const string& key);
    void setState(char key, shared_ptr<State> value);
    void setStates(map<char, shared_ptr<State>> states);
    map<char, shared_ptr<State>> getStates();
    shared_ptr<State> getState(char key);
    void executer();
};

#endif