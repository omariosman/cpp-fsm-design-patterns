#include<iostream>
#include<fstream>
#include <sstream>
#include<string>
#include<vector>
#include <tuple>

#include "../headers/FSM/FSM.h"
#include "../headers/ConcreteActions/WaitAction.h"
#include "../headers/State/State.h"
#include "../headers/Transition/Transition.h"
#include "../headers/ConcreteActions/PrintAction.h"
#include "../headers/ConcreteActions/SleepAction.h"
#include "../headers/ConcreteActions/AddMulAction.h"
#include "../headers/ConcreteActions/JMPAction.h"
#include "../headers/IFactory/ActionFactory.h"
#include "../headers/ConcreteFactory/ConcreteFactory.h"
#include "../headers/ClientReader/ClientReader.h"


using namespace std;
/*
// Helper function to trim leading and trailing whitespaces from a string
string trim(const string& str) {
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");
    if (start == string::npos) {
        return "";
    }
    return str.substr(start, end - start + 1);
}
*/

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
    
    string basedir = "/home/omarosman23/Documents/Spring 2023/OOD/Assignments/Assignment4/Assignment4/TestFiles/";
    string filename;
    cout << "Enter file name: ";
    cin >> filename;
    string filepath = basedir + filename;

    ClientReader *clientReader = new ClientReader(filepath);
    clientReader->worker();

/*
    ActionFactory* factory = new ConcreteActionFactory();
    vector<string> operands;
    FSM* fsm = new FSM();
    vector<Action*> actions;


    ifstream inputFile(filepath);
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
            //cout << "State Name: " << stateName << "\n";
            // Create new State object
            State* state = new State(stateName);
            
            // Process actions
            string actionStr = line.substr(line.find(":") + 1);
            //cout << "actionStr: " << actionStr << "\n";
            actionStr = actionStr.substr(actionStr.find_first_not_of(" \t"));
            //cout << "actionStr: " << actionStr << "\n";
            size_t pos = 0;
            string delimiter = ",";
            while ((pos = actionStr.find(delimiter)) != string::npos) {
                string actionToken = actionStr.substr(0, pos);
                actionToken = actionToken.substr(actionToken.find_first_not_of(" \t"));
                if (actionToken.substr(0, 5) == "PRINT") {
                    string actionName = "PRINT";
                    operands.clear();
                    //cout << "ation token: " << actionToken.substr(6) << "\n";
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
                //cout << "state not found\n";
            }
            // Get destination state from the map
            auto destStateIt = stateMap.find(destStateName);
            State* destState = nullptr;
            if (destStateIt != stateMap.end()) {
                destState = destStateIt->second;
            } else {
                //cout << "state not found\n";
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
    cout << "size main: " << initialState->getActionsList().size() << "\n";
    fsm->setCurrentState(initialState);
    fsm->setStates(stateMap);
    fsm->setTransitionsTable(transitionsTable);
    while(true) {
        fsm->executer();
    }
    */
    return 0;
}


