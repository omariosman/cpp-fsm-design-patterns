#ifndef TRANSITION_H
#define TRANSITION_H

#include<iostream>
#include<fstream>
#include<string>
#include<vector>


using namespace std;


class Transition {
private:
    char srcState;
    char destState;
    int transitionCode;
public:
    Transition(char _srcState,char _destState, int _transitionCode );
   // char srcState();
    //void setName(char _name);

    char getSrcState();
    char getDestState();
    int getTransitionCode();

};

#endif TRANSITION_H