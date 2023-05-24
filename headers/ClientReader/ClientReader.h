#ifndef CLIENTREADER_H
#define CLIENTREADER_H

#include<iostream>
#include<fstream>
#include<string>
#include<vector>

#include "../FSM/FSM.h"

using namespace std;

class ClientReader {
protected:
    string filepath;
public:
    ClientReader(string _filepath);
    int worker();
    virtual ~ClientReader() = default;
};

#endif 