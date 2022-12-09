//
// Created by Sergey Smykovskyi on 12/7/22.
//

#ifndef CONTEST_DAY_H
#define CONTEST_DAY_H

#include "../../lib/input/Input.h"
#include <optional>
#include <set>
#include <map>

using namespace std;

class Day {
private:
    vector<string> allLines;
    vector<string>::iterator linesIterator;
    string::iterator characterIterator;
protected:

    static void printResult(const string& result) {
        cout << "Result : " << result << "\n";
    }

public:
    virtual void findResultPart1() = 0;
    virtual void findResultPart2() = 0;

    optional<long> readNextNumber();

    vector<string> readAllLines() { return allLines; };

    Day() {
        allLines = Input().readFile();
        linesIterator = allLines.begin();
        characterIterator = linesIterator->begin();
    }
};


#endif //CONTEST_DAY_H
