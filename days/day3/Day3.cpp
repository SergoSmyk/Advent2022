//
// Created by Sergey Smykovskyi on 12/5/22.
//

#include "Day3.h"

long Day3::findResult() {
    long result = innerFindResult();
    cout << "Result : " << result;
    return result;
}

void Day3::openFile() {
    inputFile.open("input.txt");
}

void Day3::closeFile() {
    inputFile.close();
}

long Day3::innerFindResult() {
    openFile();

    long total = 0;
    if (inputFile.is_open() ) {
        while (inputFile) {
            total += readNextValue();
        }
    }
    closeFile();

    return total;
}

long Day3::readNextValue() {
    string input1;
    string input2;
    string input3;
    getline(inputFile, input1);
    getline(inputFile, input2);
    getline(inputFile, input3);
    set<char> first;
    set<char> second;
    set<char> third;

    for (int i = 0; i < input1.size(); ++i) {
        first.insert(input1[i]);
    }
    for (int i = 0; i < input2.size(); ++i) {
        second.insert(input2[i]);
    }
    for (int i = 0; i < input3.size(); ++i) {
        third.insert(input3[i]);
    }

    for (auto i = third.begin(); i != third.end(); ++i) {
        int before1 = first.size();
        int before2 = second.size();
        first.insert(*i);
        second.insert(*i);
        if (before1 == first.size() && before2 == second.size()) {
            char letter = *i;
            int value = (int)letter - 96;
            if (value < 0) {
                return value + 58;
            }
            return value;
        }
    }
    return 0;
}