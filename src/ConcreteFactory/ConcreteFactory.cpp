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

// Concrete Factory
class ConcreteActionFactory : public ActionFactory {
public:
    ConcreteActionFactory() = default; 
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
