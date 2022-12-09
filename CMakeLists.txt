cmake_minimum_required(VERSION 3.24)
project(Contest)

set(CMAKE_CXX_STANDARD 17)

add_executable(Contest main.cpp
        lib/input/Input.cpp lib/input/Input.h
        lib/base/Day.cpp lib/base/Day.h
        days/day1/Day1.cpp days/day1/Day1.h
        days/day2/Day2.cpp days/day2/Day2.h
        days/day3/Day3.cpp days/day3/Day3.h
        days/day4/Day4.cpp days/day4/Day4.h
        days/day5/Day5.cpp days/day5/Day5.h
        days/day6/Day6.cpp days/day6/Day6.h
        days/day7/Day7.cpp days/day7/Day7.h)
