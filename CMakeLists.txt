cmake_minimum_required(VERSION 3.24)
project(Day1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Day1 main.cpp
        days/day1/Day1.cpp days/day1/Day1.h
        days/day2/Day2.cpp days/day2/Day2.h
        days/day3/Day3.cpp days/day3/Day3.h
        days/day4/Day4.cpp days/day4/Day4.h)
