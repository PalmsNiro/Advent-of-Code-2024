#pragma once

#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

class Day4
{

public:
    Day4();
    void solve();

private:
    std::vector<std::string> textVec;

    void readFileToString(const std::string filepath);
    int checkDirections(int indexLine, int indexChar);
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