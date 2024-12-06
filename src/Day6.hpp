#pragma once

#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class Day6
{

public:
    Day6();
    void solve();

private:

    std::vector<std::string> map;

    void readFileToMapVec(const std::string filepath);
    int part1();
    int part2();
};

template <typename T>
void printVector(const std::vector<T> &vec)
{
    for (const auto &item : vec)
    {
        std::cout << item << ", ";
    }
    std::cout << std::endl;
}