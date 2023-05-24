#include<iostream>
#include<memory>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

#include "../headers/Transition/Transition.h"

Transition::Transition(shared_ptr<State> _srcState, shared_ptr<State> _destState, int _transitionCode) : srcState(_srcState), destState(_destState), transitionCode(_transitionCode) {
}

shared_ptr<State> Transition::getSrcState(){
    return srcState;
};
shared_ptr<State> Transition::getDestState(){
    return destState;
};
int Transition::getTransitionCode(){
    return transitionCode;
};