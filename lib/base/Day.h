//
// Created by Sergey Smykovskyi on 12/7/22.
//

#ifndef CONTEST_DAY_H
#define CONTEST_DAY_H

#include "../../lib/input/Input.h"
#include <optional>

using namespace std;

class Day {
public:
    virtual void findResultPart1() = 0;
    virtual void findResultPart2() = 0;

    optional<long> readNextNumber();

    Day() {
        allLines = Input().readFile();
        linesIterator = allLines.begin();
        characterIterator = linesIterator->begin();
    }
private:
    vector<string> allLines;
    vector<string>::iterator linesIterator;
    string::iterator characterIterator;
};


#endif //CONTEST_DAY_H
