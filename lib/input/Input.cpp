//
// Created by Sergey Smykovskyi on 12/7/22.
//

#include "Input.h"

vector<string> Input::readFile() {
    vector<string> lines;
    inputFile.open("input.txt");
    if (inputFile.is_open() ) {
        while (inputFile) {
            string line;
            getline(inputFile, line);
            if (!line.empty()) {
                lines.push_back(line);
            }
        }
        inputFile.close();
    }
    return lines;
}
