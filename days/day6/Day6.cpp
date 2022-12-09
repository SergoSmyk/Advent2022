//
// Created by Sergey Smykovskyi on 12/8/22.
//

#include "Day6.h"

void Day6::findResultPart1() {
    vector<string> allLines = readAllLines();

    string singleLine;
    for_each(allLines.begin(), allLines.end(), [&singleLine](const string& line) {
        singleLine += line;
    });

    const int uniqueSize = 4;
    for (int i = 0; i < singleLine.size() - uniqueSize; i++) {
        set<char> characters;
        for (int j = i; j < i + uniqueSize; j++) {
            characters.insert(singleLine[j]);
        }
        if (characters.size() == uniqueSize) {
            printResult(to_string( i + uniqueSize));
            break;
        }
    }

}

void Day6::findResultPart2() {
    vector<string> allLines = readAllLines();

    string singleLine;
    for_each(allLines.begin(), allLines.end(), [&singleLine](const string& line) {
        singleLine += line;
    });

    const int uniqueSize = 14;
    for (int i = 0; i < singleLine.size() - uniqueSize; i++) {
        set<char> characters;
        for (int j = i; j < i + uniqueSize; j++) {
            characters.insert(singleLine[j]);
        }
        if (characters.size() == uniqueSize) {
            printResult(to_string( i + uniqueSize));
            break;
        }
    }
}
