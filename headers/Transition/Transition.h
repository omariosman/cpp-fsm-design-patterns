#ifndef TRANSITION_H
#define TRANSITION_H

#include<iostream>
#include<memory>
#include<fstream>
#include<string>
#include<vector>


using namespace std;

#include "../State/State.h"

class State;

class Transition {
private:
    shared_ptr<State> srcState;
    shared_ptr<State> destState;
    int transitionCode;
public:
    Transition(shared_ptr<State> _srcState, shared_ptr<State> _destState, int _transitionCode );
   // char srcState();
    //void setName(char _name);

    shared_ptr<State> getSrcState();
    shared_ptr<State> getDestState();
    int getTransitionCode();

};

#endif