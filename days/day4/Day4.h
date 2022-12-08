//
// Created by Sergey Smykovskyi on 12/5/22.
//

#ifndef DAY1_DAY4_H
#define DAY1_DAY4_H


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Day4 {
public:
    struct Range {
        long start;
        long end;

        Range(long start, long end) {
            this->start = start;
            this->end = end;
        }

        bool operator==(Range second) const {
            return this->start == second.start && this->end == second.end;
        }
    };

    static Range merge(Range first, Range second);

    static long intersection(Range first, Range second);

    void fromInput(const string &line, Range*& s, Range*& e);

    long findResult();

    ifstream inputFile;

    void openFile();

    void closeFile();

    long innerFindResult();

    long readNextValue();
};


#endif //DAY1_DAY4_H
