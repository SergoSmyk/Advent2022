//
// Created by Sergey Smykovskyi on 12/5/22.
//

#include "Day1.h"

long Day1::findResult() {
    long result = innerFindResult();
    cout << "Result : " << result;
    return result;
}

void Day1::openFile() {
    inputFile.open("input.txt");
}

void Day1::closeFile() {
    inputFile.close();
}

long Day1::innerFindResult() {
    openFile();

    if (inputFile.is_open() ) {
        long total = 0;
        while (inputFile) {
            long nextValue = readNextValue();
            if (nextValue != -1) {
                total += nextValue;
            } else {
                elfsBackpacks.push_back(total * -1);
                total = 0;
            }
        }
    }
    closeFile();
    sort(elfsBackpacks.begin(), elfsBackpacks.end());
    long result = 0;

    for (int i = 0; i < 3; i++) {
        result += elfsBackpacks[i];
    }

    return result * -1;
}

long Day1::readNextValue() {
    string input;
    getline(inputFile, input);
    long value = -1;

    try {
        value = stol(input);
    } catch (invalid_argument& ex) {}
    return value;
}
