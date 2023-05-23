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
#include "../headers/ActionFactory.h"
#include "../headers/ConcreteFactory.h"


using namespace std;

// Helper function to trim leading and trailing whitespaces from a string
string trim(const string& str) {
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");
    if (start == string::npos) {
        return "";
    }
    return str.substr(start, end - start + 1);
}


#include <iostream>
#include <map>

template<typename KeyType, typename ValueType>
ValueType getFirstItemValue(const map<KeyType, ValueType>& myMap) {
    if (myMap.empty()) {
        // Handle the case when the map is empty
        throw std::out_of_range("The map is empty.");
    }

    // Access the first element and return its value
    return myMap.begin()->second;
}



int main() {
    //read transitions from file (done)
    //create states for every transition (done)
    //put them inside a vector (done)
    //read actions from the file
    //create actions dynamically by factor
    //put actions in a vector
    //read states from files
    //put actions inside the states
    //put states inside a vector of States
    //create FSM
    //pass the first state in the map to the fsm constructor
    //put transitions inside the fsm object
    //put states inside the fsm object
    //call fsm->executer()



    // Read input file
    ifstream inputFile("/home/omarosman23/Documents/Spring 2023/OOD/Assignments/Assignment4/Assignment4/src/fsm1.txt");
    if (!inputFile.is_open()) {
        cout << "Failed to open input file." << endl;
        return 1;
    }

    vector<Transition *> transitionsTable;

    // Parse input file and create states and transitions
    map<char, State*> stateMap; // Map to store created states
    string line;
    bool readStates, readTransitions = false;        
    while (getline(inputFile, line) && !line.empty()) {
        line = trim(line);
        if (line == "States:") {
            readStates = true;
            continue;
        }
        if (line == "Transitions:") {
            readStates = false;
            readTransitions = true;
            continue;
        }
        /*
        if (line == "Transitions:"){
            break;  
        }
        */
        //Read States
        if (readStates && !line.empty()) {
            // Parse state line
            char stateName = line[0];
            cout << "State Name: " << stateName << "\n";
            // Create new State object
            State* state = new State(stateName);

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
                cout << "state not found\n";
            }
            // Get destination state from the map
            auto destStateIt = stateMap.find(destStateName);
            State* destState = nullptr;
            if (destStateIt != stateMap.end()) {
                destState = destStateIt->second;
            } else {
                cout << "state not found\n";
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
    FSM *fsm = new FSM(initialState);
    fsm->setStates(stateMap);
    fsm->setTransitionsTable(transitionsTable);

    return 0;
}


