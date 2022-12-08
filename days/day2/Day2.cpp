//
// Created by Sergey Smykovskyi on 12/5/22.
//

#include "Day2.h"

long Day2::findResult() {
    long result = innerFindResult();
    cout << "Result : " << result;
    return result;
}

void Day2::openFile() {
    inputFile.open("input.txt");
}

void Day2::closeFile() {
    inputFile.close();
}

long Day2::innerFindResult() {
    openFile();

    long total = 0;
    if (inputFile.is_open() ) {
        while (inputFile) {
            total += readNextValue();
        }
    }
    closeFile();

    return total;
}

long Day2::readNextValue() {
    string input;
    getline(inputFile, input);
    long value = table2.find(input)->second;

    return value;
}