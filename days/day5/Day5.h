//
// Created by Sergey Smykovskyi on 12/7/22.
//

#ifndef DAY1_DAY5_H
#define DAY1_DAY5_H

#include "../../lib/input/Input.h"
#include "../../lib/base/Day.h"
//        [C] [B] [H]
//[W]     [D] [J] [Q] [B]
//[P] [F] [Z] [F] [B] [L]
//[G] [Z] [N] [P] [J] [S] [V]
//[Z] [C] [H] [Z] [G] [T] [Z]     [C]
//[V] [B] [M] [M] [C] [Q] [C] [G] [H]
//[S] [V] [L] [D] [F] [F] [G] [L] [F]
//[B] [J] [V] [L] [V] [G] [L] [N] [J]
// 1   2   3   4   5   6   7   8   9

class Day5 : Day {
public:
    void findResultPart1();
    void findResultPart2();

    Day5() {
        insertData(0, "WPGZVSB");
        insertData(1, "FZCBVJ");
        insertData(2, "CDZNHMLV");
        insertData(3, "BJFPZMDL");
        insertData(4, "HQBJGCFV");
        insertData(5, "BLSTQFG");
        insertData(6, "VZCGL");
        insertData(7, "GLN");
        insertData(8, "CHFJ");
    }

    void insertData(int index, string line) {
        data[index].insert(data[index].end(), line.rbegin(), line.rend());
    }

private:
    vector<char> data[9];
};

#endif //DAY1_DAY5_H

