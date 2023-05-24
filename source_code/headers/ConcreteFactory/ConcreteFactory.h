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
    Action* getProduct(const string& actionName, FSM* _fsm, const vector<string>& _operands) override;
};

#endif 
