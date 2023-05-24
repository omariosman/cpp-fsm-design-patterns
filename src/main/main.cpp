#include<iostream>
#include<string>
#include <memory>
#include "../headers/ClientReader/ClientReader.h"

using namespace std;

int main() {
    // Enter input file full path
    string basedir = "/home/omarosman23/Documents/Spring 2023/OOD/Assignments/Assignment4/Assignment4/TestFiles/";
    string filename;
    string filepath;

    try {
        cout << "Enter file name: ";
        cin >> filename;
        filepath = basedir + filename;
    } catch (const exception& e) {
        // Handle and report the exception
        cout << "Something went wrong while rading file name: " << e.what() << endl;
        exit(0);
    }

    try {
        shared_ptr<ClientReader> clientReader (new ClientReader(filepath));
        clientReader->worker();
    } catch (const exception& e) {
        // Handle and report the exception
        cout << "Something went wrong while reading the file content: " << e.what() << endl;
        exit(0);
    }

    return 0;
}


