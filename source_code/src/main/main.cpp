#include<iostream>
#include<string>
#include <memory>
#include "../../headers/ClientReader/ClientReader.h"
#include "../../headers/Helpers/helpers.h"

using namespace std;

int main() {
    // Enter input file full path
    string filepath;
    try {
        cout << "Enter file full path: ";
        cin >> filepath;
    } catch (const exception& e) {
        // Handle and report the exception
        cout << "Something went wrong while reading file name: " << e.what() << endl;
        exit(0);
    }

    try {
        cout << "filepath: " << filepath << "\n";
        shared_ptr<ClientReader> clientReader (new ClientReader(filepath));
        clientReader->worker();
    } catch (const exception& e) {
        // Handle and report the exception
        cout << "Something went wrong while reading the file content: " << e.what() << endl;
        exit(0);
    }

    return 0;
}


