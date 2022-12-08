//
// Created by Sergey Smykovskyi on 12/5/22.
//

#ifndef DAY2_DAY2_H
#define DAY2_DAY2_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Day2 {
public:
    long findResult();
private:
    ifstream inputFile;
    // Rock     A and X   1
    // Paper    B and Y   2
    // Scissors C and Z   3
    const map<string,long> table = {
            {"A X", 1 + 3},
            {"A Y", 2 + 6},
            {"A Z", 3 + 0},
            {"B X", 1 + 0},
            {"B Y", 2 + 3},
            {"B Z", 3 + 6},
            {"C X", 1 + 6},
            {"C Y", 2 + 0},
            {"C Z", 3 + 3},
    };
    // Rock     A 1   | Lose  X
    // Paper    B 2   | Draw  Y
    // Scissors C 3   | Win   Z
    const map<string,long> table2 = {
            {"A X", 3 + 0},
            {"A Y", 1 + 3},
            {"A Z", 2 + 6},
            {"B X", 1 + 0},
            {"B Y", 2 + 3},
            {"B Z", 3 + 6},
            {"C X", 2 + 0},
            {"C Y", 3 + 3},
            {"C Z", 1 + 6},
    };

    void openFile();
    void closeFile();

    long innerFindResult();
    long readNextValue();
};


#endif //DAY2_DAY2_H
