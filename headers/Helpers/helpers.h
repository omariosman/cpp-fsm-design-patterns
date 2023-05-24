#ifndef HELPERS_H
#define HELPERS_H

#include <iostream>
#include<string>
#include <map>
using namespace std;

template<typename KeyType, typename ValueType>
ValueType getFirstItemValue(const map<KeyType, ValueType>& myMap) {
    if (myMap.empty()) {
        // Handle the case when the map is empty
        throw out_of_range("The map is empty.");
    }

    // Access the first element and return its value
    return myMap.begin()->second;
}

// Helper function to trim leading and trailing whitespaces from a string
string trim(const string& str) {
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");
    if (start == string::npos) {
        return "";
    }
    return str.substr(start, end - start + 1);
}


#endif // HELPERS_H
