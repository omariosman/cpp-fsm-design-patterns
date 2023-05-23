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
#include "../headers/AddMulAction.h"
#include "../headers/JMPAction.h"

int main() {
    char stateNameA = 'A';
    State *stateA = new State(stateNameA);
    
    char stateNameB = 'B';
    State *stateB = new State(stateNameB);

    char stateNameC = 'C';
    State *stateC = new State(stateNameC);

    Transition T1(stateA, stateB, 1);
    Transition T2(stateB, stateC, 2);
    vector<Transition> transitions;
    transitions.push_back(T1);
    transitions.push_back(T2);


      
    FSM *fsm = new FSM(stateA);
    fsm->setTransitionsTable(transitions);
    fsm->setState('A', stateA);
    fsm->setState('B', stateB);
    fsm->setState('C', stateC);
    
    /*
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
    
    string addMulActionName = "AddMul";
    vector<string> operandsAddMul = {"X", "X", "*", "10"};
    Action *addMulAction = new AddMulAction(fsm, addMulActionName, operandsAddMul);
    vector<Action *> inputActionsList;
    inputActionsList.push_back(addMulAction);

    string addMulActionName1 = "AddMul";
    vector<string> operandsAddMul1 = {"X", "X", "*", "10"};
    Action *addMulAction1 = new AddMulAction(fsm, addMulActionName1, operandsAddMul);
    //vector<Action *> inputActionsList;
    inputActionsList.push_back(addMulAction1);
    */
    string jmpActionName = "JMP";
    vector<string> operandsJMP = {"C"};
    Action *jmpAction = new JMPAction(fsm, jmpActionName, operandsJMP);
    vector<Action *> inputActionsList;
    inputActionsList.push_back(jmpAction);
    stateA->setActionsList(inputActionsList);

    fsm->executer();
    /*
    fsm->setVar("X", "5"); 
    fsm->setVar("Y", "10");

    cout << fsm->getVar("X");
    fsm->executer();
    cout << fsm->getVar("X");
*/
}

