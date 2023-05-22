#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

#include "../headers/Transition.h"

Transition::Transition(State* _srcState, State* _destState, int _transitionCode) : srcState(_srcState), destState(_destState), transitionCode(_transitionCode) {
}

State* Transition::getSrcState(){
    return srcState;
};
State* Transition::getDestState(){
    return destState;
};
int Transition::getTransitionCode(){
    return transitionCode;
};