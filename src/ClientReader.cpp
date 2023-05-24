

#include<iostream>
#include<fstream>
#include<string>
#include <sstream>

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
#include "../headers/ActionFactory.h"
#include "../headers/ConcreteFactory.h"
#include "../headers/ClientReader.h"
#include "../headers/helpers.h"

ClientReader::ClientReader(string _filepath){
    filepath = _filepath;
}

int ClientReader::worker(){
    std::cout << "worker\n";
    ActionFactory* factory = new ConcreteActionFactory();
    vector<string> operands;
    FSM* fsm = new FSM();
    vector<Action*> actions;

    ifstream inputFile(filepath);
    if (!inputFile.is_open()) {
        std::cout << "Failed to open input file." << endl;
        return 1;
    }

    vector<Transition *> transitionsTable;
    // Parse input file and create states and transitions
    map<char, State*> stateMap; // Map to store created states
    string line;
    bool readStates = false;
    bool readTransitions = false;  
    while (getline(inputFile, line) && !line.empty()) {
        line = trim(line);
        // Read Var section
        if (line.find("VAR") != std::string::npos) {
            // Parse variables line
            line.erase(0, 4);
            istringstream iss(line);
            string variable;
            
            while (getline(iss, variable, ',')) {
                // Trim leading and trailing whitespaces from the variable
                variable.erase(0, variable.find_first_not_of(" \t"));
                variable.erase(variable.find_last_not_of(" \t") + 1);
                // Call fsm->setVar for each variable
                fsm->setVar(variable, "0");
            }          
        }

        if (line == "States:") {
            readStates = true;
            continue;
        }
        if (line == "Transitions:") {
            readStates = false;
            readTransitions = true;
            continue;
        }

        //Read States
        if (readStates && !line.empty()) {
            actions.clear();
            // Parse state line
            char stateName = line[0];

            // Create new State object
            State* state = new State(stateName);
            
            // Process actions
            string actionStr = line.substr(line.find(":") + 1);
            //std::cout << "actionStr: " << actionStr << "\n";
            actionStr = actionStr.substr(actionStr.find_first_not_of(" \t"));
            //std::cout << "actionStr: " << actionStr << "\n";
            size_t pos = 0;
            string delimiter = ",";
            while ((pos = actionStr.find(delimiter)) != string::npos) {
                string actionToken = actionStr.substr(0, pos);
                actionToken = actionToken.substr(actionToken.find_first_not_of(" \t"));
                if (actionToken.substr(0, 5) == "PRINT") {
                    string actionName = "PRINT";
                    operands.clear();
                    //std::cout << "ation token: " << actionToken.substr(6) << "\n";
                    operands.push_back(actionToken.substr(6));
                    Action* action = factory->getProduct(actionName, fsm, actionName, operands);
                    actions.push_back(action);
                } else if (actionToken.find("=") != string::npos) {
                    string actionName = "AddMul";
                    operands.clear();
                    operands.push_back(actionToken.substr(0, actionToken.find("=")));
                    operands.push_back(actionToken.substr(actionToken.find("=") + 1));
                    operands.push_back(actionToken.substr(actionToken.find("=") + 1, 1));
                    operands.push_back(actionToken.substr(actionToken.find("=") + 2));
                    Action* action = factory->getProduct(actionName, fsm, actionName, operands);
                    actions.push_back(action);
                } else if (actionToken.substr(0, 5) == "sleep") {
                    string actionName = "sleep";
                    operands.clear();
                    operands.push_back(actionToken.substr(6));
                    Action* action = factory->getProduct(actionName, fsm, actionName, operands);
                    actions.push_back(action);
                } else if (actionToken == "wait") {
                    string actionName = "wait";
                    operands.clear();
                    Action* action = factory->getProduct(actionName, fsm, actionName, operands);
                    actions.push_back(action);
                } else if (actionToken == "end") {
                    string actionName = "end";
                    operands.clear();
                    Action* action = factory->getProduct(actionName, fsm, actionName, operands);
                    actions.push_back(action);
                } else if (actionToken.substr(0, 3) == "JMP") {
                    string actionName = "JMP";
                    operands.clear();
                    operands.push_back(actionToken.substr(4));
                    Action* action = factory->getProduct(actionName, fsm, actionName, operands);
                    actions.push_back(action);
                }
                actionStr.erase(0, pos + delimiter.length());
            }
            state->setActionsList(actions);
            // Put the state in the map
            stateMap[stateName] = state;
        }
        //Read Transitions
        if (readTransitions && !line.empty()) {
            // Parse transition line
            char srcStateName, destStateName;
            int transitionCode;
            sscanf(line.c_str(), "%c, %c, %d", &srcStateName, &destStateName, &transitionCode);
            
            // Get source state from the map
            auto srcStateIt = stateMap.find(srcStateName);
            State* srcState = nullptr;
            if (srcStateIt != stateMap.end()) {
                srcState = srcStateIt->second;
            } else {
                //std::cout << "state not found\n";
            }
            // Get destination state from the map
            auto destStateIt = stateMap.find(destStateName);
            State* destState = nullptr;
            if (destStateIt != stateMap.end()) {
                destState = destStateIt->second;
            } else {
                //std::cout << "state not found\n";
            } 

            // Create transition
            Transition* transition = new Transition(srcState, destState, transitionCode);
            transitionsTable.push_back(transition);
        }
    }
    
    // Close input file
    inputFile.close();

    //Get the initial state form the first state in the first transition line in the input file
    State *initialState = getFirstItemValue(stateMap);
    //Create the FSM object and send the initial state to it in the constructor
    //FSM *fsm = new FSM(initialState);
    std::cout << "size main: " << initialState->getActionsList().size() << "\n";
    fsm->setCurrentState(initialState);
    fsm->setStates(stateMap);
    fsm->setTransitionsTable(transitionsTable);
    while(true) {
        fsm->executer();
    }
}

/*
template<typename KeyType, typename ValueType>
ValueType ClientReader::getFirstItemValue(const map<KeyType, ValueType>& myMap) {
    if (myMap.empty()) {
        // Handle the case when the map is empty
        throw std::out_of_range("The map is empty.");
    }

    // Access the first element and return its value
    std::cout << "first: " << myMap.begin()->first << "\n"; 
    return myMap.begin()->second;
}
*/


