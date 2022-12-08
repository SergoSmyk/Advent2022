//
// Created by Sergey Smykovskyi on 12/5/22.
//

#ifndef CONTEST_DAY3_H
#define CONTEST_DAY3_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Day3 {
public:
    long findResult();
private:
    ifstream inputFile;

    void openFile();
    void closeFile();

    long innerFindResult();
    long readNextValue();
};


#endif //CONTEST_DAY3_H
