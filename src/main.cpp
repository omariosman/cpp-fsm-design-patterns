#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include <tuple>

#include "FSM.h"
//#include "Action.h"
#include "WaitAction.h"
#include "State.h"
#include "Transition.h"

int main() {
    char stateNameA = 'A';
    State *stateA = new State(stateNameA);
    
    char stateNameB = 'B';
    State *stateB = new State(stateNameB);

    Transition T1(stateA, stateB, 1);
    Transition T2(stateB, stateA, 2);
    vector<Transition> transitions;
    transitions.push_back(T1);
    transitions.push_back(T2);


      
    FSM *fsm = new FSM(stateA);
    fsm->setTransitionsTable(transitions);

    string actionName = "wait";
    vector<string> operands = {};
    Action *waitAction = new WaitAction(fsm, actionName, operands);
    vector<Action *> inputActionsList;
    inputActionsList.push_back(waitAction);
    
    stateA->setActionsList(inputActionsList);
    stateB->setActionsList(inputActionsList);

    fsm->executer();

 

   
}

