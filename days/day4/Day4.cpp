//
// Created by Sergey Smykovskyi on 12/5/22.
//

#include "Day4.h"

long Day4::findResult() {
    long result = innerFindResult();
    cout << "Result : " << result;
    return result;
}

long Day4::innerFindResult() {
    openFile();

    long total = 0;
    if (inputFile.is_open()) {
        while (inputFile) {
            total += readNextValue();
        }
    }
    closeFile();

    return total;
}


void Day4::openFile() {
    inputFile.open("input.txt");
}

void Day4::closeFile() {
    inputFile.close();
}

long Day4::readNextValue() {
    string input1;
    getline(inputFile, input1);

    if (input1.empty()) {
        return 0;
    }

    Day4::Range *first = nullptr;
    Day4::Range *second = nullptr;
    fromInput(input1, first, second);

    return intersection(*first, *second);
//
//    Day4::Range merged = merge(*first, *second);
//    if (*first == merged || *second == merged) {
//        cout << input1 << " = true" << "\n";
//        return 1;
//    }
//    cout << input1 << " = false" << "\n";
//    return 0;
}

Day4::Range Day4::merge(Day4::Range first, Day4::Range second) {
    return {
            (first.start <=second.start)?first.start:second.start,
            (first.end>=second.end)?first.end:second.end
    };
}


long Day4::intersection(Day4::Range first, Day4::Range second) {
    Range smaller = first;
    Range larger = second;
    if (first.start > second.start) {
        swap(smaller, larger);
    }

    if (larger.start <= smaller.end) {
        return 1;
    }

    return 0;
}


void Day4::fromInput(const string &line, Range *&first, Range *&second) {
    vector<char> start;
    vector<char> end;

    bool isEndValue = false;

    for (char letter: line) {
        if (letter == ',') {
            first = new Range(stol(start.data()),stol(end.data()));
            isEndValue = false;
            start.clear();
            start.shrink_to_fit();
            end.clear();
            end.shrink_to_fit();
        } else if (letter == '-') {
            isEndValue = true;
        } else {
            if (isEndValue) {
                end.push_back(letter);
            } else {
                start.push_back(letter);
            }
        }
    }
    second = new Range(
            stol(start.data()),
            stol(end.data())
    );
}