#include "../headers/Action.h"
#include "../headers/Transition.h"
#include<tuple>

Action::Action(FSM *_fsm, string _name, vector<string> _operands)
     : fsm(_fsm), name(_name), operands(_operands)  {

}

string Action::getName() {
    return name;
}

void Action::setName(string _name) {
    name = _name;
}

void Action::setFSM(FSM *_fsm) {
    fsm = _fsm;
}


char Action::executer() {
    cout << "Action executer\n";
    //This logic will be implemented in the wait action
    
    bool found = false;
    vector<Transition> transitions = fsm->getTransitionsTable();
    for (int i=0; i<transitions.size(); i++) {
        char sourceState, destState;
        int input;
        cin >> input;
        Transition transition= transitions[i];
        //tie(sourceState, destState, input) = transition;
        //auto [sourceState, destState, input] = transition;
        sourceState= transition.getSrcState();
        destState = transition.getDestState();

        State* currentState= fsm-> getCurrentState();
        char currentStateName = currentState->getName();
        if (sourceState == currentStateName && input == transition.getTransitionCode()){
            found = true;
            return destState;
        } 
    }
    if (!found) {
        cout << "Invalid transition\n try again";
    }    
}



