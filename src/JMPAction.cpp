#include "../headers/JMPAction.h"
#include "../headers/Transition.h"
#include "../headers/State.h"
#include "../headers/PrintAction.h"

#include<tuple>
#include <typeinfo>

JMPAction::JMPAction(FSM *_fsm, string _name, vector<string> _operands)
     : Action(_fsm, _name, _operands) {
}

string JMPAction::getName() {
    return name;
}

void JMPAction::setName(string _name) {
    name = _name;
}

void JMPAction::setFSM(FSM *_fsm) {
    fsm = _fsm;
}

void JMPAction::executer() {
    //cout << "JMPAction executer\n";
    char destStateName = operands[0][0];
    char currentStateName= fsm->getCurrentState()->getName();
    vector<Transition *> transitions = fsm->getTransitionsTable();
    bool canReach = canReachDestination(currentStateName, destStateName, transitions);
    
    if(canReach) {
        cout<< "Destination can be reached.\n"<<endl;
        State* destState = fsm->getState(destStateName);
        cout << "name: " << destState->getName() << "\n";
        fsm->setCurrentState(destState);
        fsm->executer();
    }
    else {
        //no path found
        cout<<endl<<"Invalid transition, no path found to destination state"<<endl;
    }
}

bool JMPAction::canReachDestination(char currentState, char destinationState, vector<Transition *> transitions) {
    // Base case: If the current state is the same as the destination state, return true
    if (currentState == destinationState) {
        return true;
    }

    // Iterate through each transition
    for (Transition *transition : transitions) {
        // Check if the source state of the transition matches the current state
        if (transition->getSrcState()->getName() == currentState) {
            // Recursively check if we can reach the destination state from the destination of this transition
            if (canReachDestination(transition->getDestState()->getName(), destinationState, transitions)) {
                return true;  // Path found
            }
        }
    }

    // No valid path found
    return false;
}



