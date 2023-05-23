#ifndef CONCRETEACTIONFACTORY_H
#define CONCRETEACTIONFACTORY_H

#include<iostream>
#include<memory>

#include "../headers/Action.h"
#include "../headers/AddMulAction.h"
#include "../headers/EndAction.h"
#include "../headers/WaitAction.h"
#include "../headers/SleepAction.h"
#include "../headers/PrintAction.h"
#include "../headers/JMPAction.h"

#include "../headers/ActionFactory.h"

// Concrete Factory
class ConcreteActionFactory : public ActionFactory {
public:
    Action* getProduct(const std::string& actionName, FSM* _fsm, const std::string& _name, const std::vector<std::string>& _operands) override {
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
            std::cout << "Error: Unknown action name." << std::endl;
        }

        return action;
    }
};

#endif // CONCRETEACTIONFACTORY_H
