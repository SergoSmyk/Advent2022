//
// Created by Sergey Smykovskyi on 12/8/22.
//

#include "Day7.h"

#include <utility>

void Day7::findResultPart1() {
    auto* root = new Directory(nullptr);
    readInput(root);

    printResult(to_string(root->countTotalDirsSizeWithLimit(100000)));
}

void Day7::findResultPart2() {
    auto* root = new Directory(nullptr);
    readInput(root);

    long fullSize = 70000000;
    long requiredSize = 30000000;
    long maxAvailable = fullSize - requiredSize;
    long usedSpace = root->findSize();
    long minCleanup = usedSpace - maxAvailable;

    printResult(to_string(root->findSmallestDirWhichBiggerThan(minCleanup)));
}

void Day7::readInput(Directory* root) {
    auto allLines = readAllLines();
    Directory* currentDirectory = root;

    bool isLSMode = false;
    for (const string& line: allLines) {
        if (line.find('$') == 0) {
            isLSMode = false;
            if (line.find(" cd ") == 1) {
                string goTo = line.substr(5); // ("$ cd ")
                if (goTo == "..") {
                    currentDirectory = currentDirectory->parent;
                } else {
                    currentDirectory = currentDirectory->getChildDirectory(goTo);
                }
            } else if (line.find(" ls") == 1) {
                isLSMode = true;
            }
        } else if (isLSMode) {
            if (line.find("dir") == 0) {
                string childDirName = line.substr(4);
                currentDirectory->createChildDir(childDirName);
            } else {
                int spacePosition = line.find(' ');
                long fileSize = stol(line.substr(0, spacePosition));
                string fileName = line.substr(spacePosition + 1);
                currentDirectory->addFile(fileName, fileSize);
            }
        }
    }
}

void Directory::addFile(const string& fileName, long size) {
    files.insert(files.end(), pair<string, long>(fileName, size));
}

void Directory::createChildDir(const string& dirName) {
    auto* childDir = new Directory(this);
    childDirs.insert(childDirs.end(), pair<string, Directory*>(dirName, childDir));
}

Directory* Directory::getChildDirectory(const string& dirName) {
    return childDirs.at(dirName);
}

long Directory::findSize() {
    long size = 0;

    for_each(files.begin(), files.end(), [&size](const pair<string, long>& entry) {
        size += entry.second;
    });

    for_each(childDirs.begin(), childDirs.end(), [&size](pair<string, Directory*> entry) {
        size += entry.second->findSize();
    });

    return size;
}

long Directory::countTotalDirsSizeWithLimit(long maxSize) {
    long total = 0;
    long size = findSize();
    if (size <= maxSize) {
        total += size;
    }

    for_each(childDirs.begin(), childDirs.end(), [&total, &maxSize](pair<string, Directory*> entry) {
        total += entry.second->countTotalDirsSizeWithLimit(maxSize);
    });

    return total;
}

long Directory::findSmallestDirWhichBiggerThan(long size) {
    long dirSize = findSize();
    if (dirSize >= size) {
        long minSize = dirSize;
        for_each(childDirs.begin(), childDirs.end(), [&minSize, &size](pair<string, Directory*> entry) {
            long childSize = entry.second->findSmallestDirWhichBiggerThan(size);
            if (childSize < minSize) {
                minSize = childSize;
            }
        });
        return minSize;
    }

    return LONG_MAX;
}
