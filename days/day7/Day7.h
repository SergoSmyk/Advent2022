//
// Created by Sergey Smykovskyi on 12/8/22.
//

#ifndef CONTEST_DAY7_H
#define CONTEST_DAY7_H

#include "../../lib/base/Day.h"

struct Directory {
    Directory* parent;
    map<string, Directory*> childDirs;
    map<string, long> files;

    explicit Directory(Directory* parent) {
        this->parent = parent;
    }

    void addFile(const string& fileName, long size);

    void createChildDir(const string& dirName);

    Directory* getChildDirectory(const string& dirName);

    long findSize();

    long countTotalDirsSizeWithLimit(long maxSize);

    long findSmallestDirWhichBiggerThan(long size);
};

class Day7 : Day {
public:
    void findResultPart1() override;

    void findResultPart2() override;

private:
    void readInput(Directory* root);
};


#endif //CONTEST_DAY7_H
