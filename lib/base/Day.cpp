//
// Created by Sergey Smykovskyi on 12/7/22.
//

#include "Day.h"

optional<long> Day::readNextNumber() {
    if (characterIterator == linesIterator->end() || linesIterator == allLines.end()) {
        if (linesIterator == allLines.end()) {
            return nullopt;
        }
        advance(linesIterator, 1);
        if (linesIterator->empty()) {
            return nullopt;
        }
        characterIterator = linesIterator->begin();
    }

    vector<char> digits;
    while (!isdigit(*characterIterator)) {
        advance(characterIterator, 1);
    }
    do {
        digits.push_back(*characterIterator);
        advance(characterIterator, 1);
    } while (isdigit(*characterIterator) && characterIterator != linesIterator->end());

    return stol(digits.data());
}

