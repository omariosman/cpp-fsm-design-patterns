#include<iostream>
#include<memory>

#include "../headers/IAction/Action.h"
#include "../headers/ConcreteActions/AddMulAction.h"
#include "../headers/ConcreteActions/WaitAction.h"
#include "../headers/ConcreteActions/SleepAction.h"
#include "../headers/ConcreteActions/PrintAction.h"
#include "../headers/ConcreteActions/JMPAction.h"
#include "../headers/ConcreteActions/EndAction.h"
#include "../headers/IFactory/ActionFactory.h"
#include "../headers/ConcreteFactory/ConcreteFactory.h"

// Concrete Factory
Action* ConcreteActionFactory::getProduct(const string& actionName, FSM* _fsm, const vector<string>& _operands) {
    try {
        Action* action = nullptr;
        if (actionName == "AddMul") {
            action = new AddMulAction(_fsm, actionName, _operands);
        } else if (actionName == "PRINT") {
            action = new PrintAction(_fsm, actionName, _operands);
        } else if (actionName == "JMP") {
            action = new JMPAction(_fsm, actionName, _operands);
        } else if (actionName == "sleep") {
            action = new SleepAction(_fsm, actionName, _operands);
        } else if (actionName == "wait") {
            action = new WaitAction(_fsm, actionName, _operands);
        } else if (actionName == "end") {
            action = new EndAction(_fsm, actionName, _operands);
        } else {
            // Unknown action name, handle the error
            cout << "Error: Unknown action name." << endl;
        }
        
        return action;
    } catch (const exception& e) {
        // Handle and report the exception
        cout << "Something went wrong while creating actions objects in the factory: " << e.what() << endl;
    }

   
}

