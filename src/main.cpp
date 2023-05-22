#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include <tuple>

#include "../headers/FSM.h"
//#include "Action.h"
#include "../headers/WaitAction.h"
#include "../headers/State.h"
#include "../headers/Transition.h"
#include "../headers/PrintAction.h"
#include "../headers/SleepAction.h"
#include "../headers/EndAction.h"

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


    string printActionName = "Print";
    vector<string> operandsPrint = {"test Print Action"};
    Action *printAction = new PrintAction(fsm, printActionName, operandsPrint);
    vector<Action *> inputActionsList;
    inputActionsList.push_back(printAction);
    

    string sleepActionName = "sleep";
    vector<string> operandsSleep = {"2"};
    Action *sleepAction = new SleepAction(fsm, sleepActionName, operandsSleep);
    inputActionsList.push_back(sleepAction);


    string waitActionName = "wait";
    vector<string> operandsWait = {};
    Action *waitAction = new WaitAction(fsm, waitActionName, operandsWait);
    inputActionsList.push_back(waitAction);
    

    stateA->setActionsList(inputActionsList);

   
    //putting end in B only
    string endActionName = "end";
    vector<string> operandsEnd = {};
    Action *endAction = new EndAction(fsm, endActionName, operandsEnd);
    inputActionsList.push_back(endAction);
    
    
    stateB->setActionsList(inputActionsList);

    fsm->executer();
    fsm->executer();
 

   
}

