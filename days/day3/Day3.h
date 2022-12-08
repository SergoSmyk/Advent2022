//
// Created by Sergey Smykovskyi on 12/5/22.
//

#ifndef DAY3_DAY3_H
#define DAY3_DAY3_H

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


#endif //DAY3_DAY3_H
