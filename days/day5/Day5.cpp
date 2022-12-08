//
// Created by Sergey Smykovskyi on 12/7/22.
//

#include "Day5.h"

// Part 1
void Day5::findResultPart1() {
    optional<long> optCount = readNextNumber();
    optional<long> optFrom = readNextNumber();
    optional<long> optTo = readNextNumber();

    while (optCount.has_value()) {
        long count = optCount.value();
        long from = optFrom.value() - 1;
        long to = optTo.value() - 1;

        data[to].insert(
                data[to].end(),
                data[from].rbegin(),
                next(data[from].rbegin(), count)
                );
        data[from].erase(prev(data[from].end(), count),data[from].end());
        data[from].shrink_to_fit();

        optCount = readNextNumber();
        optFrom = readNextNumber();
        optTo = readNextNumber();
    }

    string result;
    for (vector<char> column : data) {
        if (!column.empty()) {
            result += column.back();
        }
    }

    cout << "Result Part 1:" << result << "\n";
}

void Day5::findResultPart2() {
    optional<long> optCount = readNextNumber();
    optional<long> optFrom = readNextNumber();
    optional<long> optTo = readNextNumber();

    while (optCount.has_value()) {
        long count = optCount.value();
        long from = optFrom.value() - 1;
        long to = optTo.value() - 1;

        data[to].insert(
                data[to].end(),
                prev(data[from].end(), count),
                data[from].end()
                );
        data[from].erase(prev(data[from].end(), count),data[from].end());
        data[from].shrink_to_fit();

        optCount = readNextNumber();
        optFrom = readNextNumber();
        optTo = readNextNumber();
    }

    string result;
    for (vector<char> column : data) {
        if (!column.empty()) {
            result += column.back();
        }
    }

    cout << "Result Part 2:" << result;
}