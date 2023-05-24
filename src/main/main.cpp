#include<iostream>
#include<string>
#include "../headers/ClientReader/ClientReader.h"

using namespace std;

int main() {
    // Enter input file full path
    string basedir = "/home/omarosman23/Documents/Spring 2023/OOD/Assignments/Assignment4/Assignment4/TestFiles/";
    string filename;
    cout << "Enter file name: ";
    cin >> filename;
    string filepath = basedir + filename;

    ClientReader *clientReader = new ClientReader(filepath);
    clientReader->worker();

    return 0;
}


