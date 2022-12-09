#include <iostream>
#include "days/day1/Day1.h"
#include "days/day2/Day2.h"
#include "days/day3/Day3.h"
#include "days/day4/Day4.h"
#include "days/day5/Day5.h"
#include "days/day6/Day6.h"
#include "days/day7/Day7.h"

using namespace std;

int main() {
    Day7* part1 = new Day7();
    part1 ->findResultPart1();
    Day7* part2 = new Day7();
    part2 ->findResultPart2();

    return 0;
}
