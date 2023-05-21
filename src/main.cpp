#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include <tuple>

#include "FSM.h"
#include "Action.h"
#include "State.h"
#include "Transition.h"

int main() {
    /*vector<Transition> transitions = {
        make_tuple('A', 'B', 1),
        make_tuple('B', 'A', 2),
        make_tuple('A', 'A', 2),
        make_tuple('B', 'B', 1),
        make_tuple('B', 'C', 3),
        make_tuple('B', 'C', 2),
        make_tuple('D', 'A', 5)
    };*/

    Transition T1('A', 'B', 1);
    Transition T2('B', 'A', 2);
    vector<Transition> transitions;
    transitions.push_back(T1);
    transitions.push_back(T2);

    char stateNameA = 'A';
    State *stateA = new State(stateNameA);
    
    
    char stateNameB = 'B';
    State *stateB = new State(stateNameB);
      
    FSM *fsm = new FSM(stateA);
    fsm->setTransitionsTable(transitions);

    string actionName = "AddMul";
    vector<string> operands = {"x", "x", "+", "1"};
    Action AddMul(fsm, actionName, operands);
    vector<Action> inputActionsList;
    inputActionsList.push_back(AddMul);
    
    stateA->setActionsList(inputActionsList);
    
    fsm->executer();
   
}

