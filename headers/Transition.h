#ifndef TRANSITION_H
#define TRANSITION_H

#include<iostream>
#include<fstream>
#include<string>
#include<vector>


using namespace std;

#include "State.h"

class State;

class Transition {
private:
    State *srcState;
    State *destState;
    int transitionCode;
public:
    Transition(State *_srcState,State *_destState, int _transitionCode );
   // char srcState();
    //void setName(char _name);

    State *getSrcState();
    State *getDestState();
    int getTransitionCode();

};

#endif TRANSITION_H