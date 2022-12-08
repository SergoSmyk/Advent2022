//
// Created by Sergey Smykovskyi on 12/7/22.
//

#ifndef CONTEST_INPUT_H
#define CONTEST_INPUT_H

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Input {
public:
    vector<string> readFile();
private:
    ifstream inputFile;
};


#endif //CONTEST_INPUT_H
