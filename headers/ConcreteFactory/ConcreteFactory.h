#ifndef CONCRETEACTIONFACTORY_H
#define CONCRETEACTIONFACTORY_H

#include<iostream>
#include<memory>

#include "../IAction/Action.h"
#include "../ConcreteActions/AddMulAction.h" 
#include "../ConcreteActions/WaitAction.h"
#include "../ConcreteActions/SleepAction.h"
#include "../ConcreteActions/PrintAction.h"
#include "../ConcreteActions/JMPAction.h"
#include "../ConcreteActions/EndAction.h"

#include "../IFactory/ActionFactory.h"

// Concrete Factory
class ConcreteActionFactory : public ActionFactory {
public:
    Action* getProduct(const string& actionName, FSM* _fsm, const string& _name, const vector<string>& _operands) override {
        Action* action = nullptr;

        if (actionName == "AddMul") {
            action = new AddMulAction(_fsm, _name, _operands);
        } else if (actionName == "PRINT") {
            action = new PrintAction(_fsm, _name, _operands);
        } else if (actionName == "JMP") {
            action = new JMPAction(_fsm, _name, _operands);
        } else if (actionName == "sleep") {
            action = new SleepAction(_fsm, _name, _operands);
        } else if (actionName == "wait") {
            action = new WaitAction(_fsm, _name, _operands);
        } else if (actionName == "end") {
            action = new EndAction(_fsm, _name, _operands);
        } else {
            // Unknown action name, handle the error
            cout << "Error: Unknown action name." << endl;
        }

        return action;
    }
};

#endif 
