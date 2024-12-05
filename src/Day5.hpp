#pragma once

#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

class Day5
{

public:
    Day5();
    void solve();

private:
    std::vector<std::pair<int, int>> orderingRules;
    std::vector<std::vector<int>> pageNumbers;

    void readFileToVectors(const std::string filepath);
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