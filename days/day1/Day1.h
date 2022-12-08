//
// Created by Sergey Smykovskyi on 12/5/22.
//
#ifndef DAY1_DAY1_H
#define DAY1_DAY1_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Day1 {
public:
     long findResult();
private:
    ifstream inputFile;
    vector<long> elfsBackpacks;

    void openFile();
    void closeFile();

    long innerFindResult();
    long readNextValue();
};


#endif //DAY1_DAY1_H
