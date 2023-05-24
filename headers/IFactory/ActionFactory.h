#ifndef ACTIONFACTORY_H
#define ACTIONFACTORY_H

#include<iostream>
#include<memory>

#include "../IAction/Action.h"

// Factory Interface
class ActionFactory {
public:
    virtual Action* getProduct(const string& actionName, FSM* _fsm, const string& _name, const vector<string>& _operands) = 0;
    virtual ~ActionFactory() {}
};

#endif 
