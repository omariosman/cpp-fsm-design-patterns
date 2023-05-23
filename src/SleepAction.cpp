#include "../headers/SleepAction.h"
#include "../headers/Transition.h"
#include "../headers/State.h"
#include<tuple>
#include <chrono>
#include <thread>
using namespace std;

SleepAction::SleepAction(FSM *_fsm, string _name, vector<string> _operands)
     : Action(_fsm, _name, _operands) {
}

string SleepAction::getName() {
    return name;
}

void SleepAction::setName(string _name) {
    name = _name;
}

void SleepAction::setFSM(FSM *_fsm) {
    fsm = _fsm;
}


void SleepAction::executer() {
    //cout << "SleepAction executer\n";
    string inputSeconds = operands[0]; 
    int seconds = stoi(inputSeconds); 
    this_thread::sleep_for(chrono::seconds(seconds));
}



