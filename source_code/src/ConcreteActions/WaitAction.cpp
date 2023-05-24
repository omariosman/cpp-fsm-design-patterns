#include "../../headers/ConcreteActions/WaitAction.h"
#include "../../headers/Transition/Transition.h"
#include "../../headers/State/State.h"
#include<tuple>

WaitAction::WaitAction(FSM *_fsm, string _name, vector<string> _operands)
     : Action(_fsm, _name, _operands) {
}

string WaitAction::getName() {
    return name;
}

void WaitAction::setName(string _name) {
    name = _name;
}

void WaitAction::setFSM(FSM *_fsm) {
    fsm = _fsm;
}

void WaitAction::executer() {
    //cout << "WaitAction executer\n";
    bool found = false;
    vector<Transition *> transitions = fsm->getTransitionsTable();
    try {
        while (true) {
            int input;
            cout << "\nEnter a transition code: ";
            cin >> input;
            //cout << "transitions size: " << transitions.size();
            for (long unsigned int i = 0; i < transitions.size(); i++) {
                Transition * transition = transitions[i];
                
                shared_ptr<State> sourceState = transition->getSrcState();
                shared_ptr<State> destState = transition->getDestState();
                shared_ptr<State> currentState= fsm->getCurrentState();
                char currentStateName = currentState->getName();
                if (sourceState->getName() == currentStateName && input == transition->getTransitionCode()){
                    found = true;
                    //cout <<"found\n";
                    //cout << "next state name: " << destState->getName()<<"\n";
                    fsm->setCurrentState(destState);
                } 
            }
            if (!found) {
                cout << "Invalid transition. Try again!";
            } else {
                break;
            }
        }
    } catch (const exception& e) {
        // Handle and report the exception
        cout << "Something went wrong in the wait action: " << e.what() << endl;
        return;
    }
}



