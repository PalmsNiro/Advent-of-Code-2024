#pragma once

#pragma once

#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

class Day3
{

public:
    Day3();
    void solve();

private:
    std::string text;

    void readFileToString(const std::string filepath);
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