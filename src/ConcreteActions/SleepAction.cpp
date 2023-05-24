#include "../headers/ConcreteActions/SleepAction.h"
#include "../headers/Transition/Transition.h"
#include "../headers/State/State.h"
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
    try {
        inputSeconds = operands[0]; 
    } catch (const exception& e) {
        // Handle and report the exception
        cout << "Something went wrong while reading operands: " << e.what() << endl;
        return;
    }
 
    int seconds = stoi(inputSeconds);
    try {
        seconds = stoi(inputSeconds);
    } catch (const exception& e) {
        // Handle and report the exception
        cout << "Something went wrong while converting string to integer in sleep action: " << e.what() << endl;
        return;
    }
 
    try {
        this_thread::sleep_for(chrono::seconds(seconds));
    } catch (const exception& e) {
        // Handle and report the exception
        cout << "Something went wrong while executing the sleep action: " << e.what() << endl;
        return;
    }
}



