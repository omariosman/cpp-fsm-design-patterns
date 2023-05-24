#ifndef ACTIONFACTORY_H
#define ACTIONFACTORY_H

#include<iostream>
#include<memory>

#include "Action.h"

// Factory Interface
class ActionFactory {
public:
    virtual Action* getProduct(const std::string& actionName, FSM* _fsm, const std::string& _name, const std::vector<std::string>& _operands) = 0;
    virtual ~ActionFactory() {}
};

#endif 
