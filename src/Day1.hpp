#pragma once

#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

class Day1
{

public:
    Day1();
    void solve();

private:
    std::vector<int> arr1;
    std::vector<int> arr2;

    void readFileToArrays(const std::string filepath);
    void sortArrays();
    int part1();
    int part2();
};

template <typename T>
void printVector(std::vector<T> &vec)
{
    for (const auto &item : vec)
    {
        std::cout << item << ", ";
    }
    std::cout << std::endl;
}