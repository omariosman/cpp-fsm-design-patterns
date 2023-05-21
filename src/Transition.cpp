#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

#include "../headers/Transition.h"

Transition::Transition(char _srcState,char _destState, int _transitionCode) : srcState(_srcState), destState(_destState), transitionCode(_transitionCode) {
}

char Transition::getSrcState(){
    return srcState;
};
char Transition::getDestState(){
    return destState;
};
int Transition::getTransitionCode(){
    return transitionCode;
};