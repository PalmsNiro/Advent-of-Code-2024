#pragma once

#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

class Day2
{

public:
    Day2();
    void solve();

private:
    std::vector<std::string> lines;

    void readFileToArrays(const std::string filepath);
    int part1();
    int part2();
    bool checkIfSafe(const std::vector<int> &check);
    bool checkIfSafeP2(const std::vector<int> &check);
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