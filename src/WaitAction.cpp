#include "../headers/WaitAction.h"
#include "../headers/Transition.h"
#include "../headers/State.h"
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


char WaitAction::executer() {
    cout << "WaitAction executer\n";
    //This logic will be implemented in the wait action
    
    bool found = false;
    vector<Transition> transitions = fsm->getTransitionsTable();
    while (true) {
        int input;
        cout << "Enter a transition code: ";
        cin >> input;
        for (int i = 0; i < transitions.size(); i++) {
            Transition transition = transitions[i];
            
            State* sourceState = transition.getSrcState();
            State* destState = transition.getDestState();

            State* currentState= fsm->getCurrentState();
            char currentStateName = currentState->getName();
            if (sourceState->getName() == currentStateName && input == transition.getTransitionCode()){
                found = true;
                cout <<"found\n";
                cout << "next state name: " << destState->getName()<<"\n";
                fsm->setCurrentState(destState);
            } 
        }
        if (!found) {
            cout << "Invalid transition. Try again!";
        } else {
            break;
        }
    }
}



