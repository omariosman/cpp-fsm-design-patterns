#ifndef CLIENTREADER_H
#define CLIENTREADER_H

#include<iostream>
#include<fstream>
#include<string>
#include<vector>

#include "FSM.h"

using namespace std;

class ClientReader {
protected:
    //FSM *fsm;
    string filepath;
public:
    ClientReader(string _filepath);
    int worker();
    //void setFSM(FSM* _fsm);
    //FSM* getFSM();
    //template<typename KeyType, typename ValueType>
    //ValueType getFirstItemValue(const map<KeyType, ValueType>& myMap);
    virtual ~ClientReader() = default;
};

#endif 