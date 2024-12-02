#include "Day2.hpp"
#include <sstream>

using std::cout;
using std::endl;
using std::stoi;
using std::string;
using std::vector;

Day2::Day2() {};

void Day2::readFileToArrays(const string filepath)
{
    std::ifstream file1(filepath);
    if (!file1.is_open())
    {
        cout << "Fehler beim Öffnen der Datei!" << endl;
    }

    string line;
    while (std::getline(file1, line))
    {
        // push back line
        lines.push_back(line);
    }
    file1.close();
}

bool Day2::checkIfSafe(const vector<int> &check)
{
    // bool lowToHigh = check.at(0) < check.at(1) ? true : false;
    bool lowToHigh = check[0] < check[1];

    for (int i = 0; i < check.size() - 1; i++)
    {
        int diff = check[i + 1] - check[i];

        // Prüfe Richtung & Differenz
        if (lowToHigh)
        {
            if (diff <= 0 || diff > 3)
                return false;
        }
        else
        {
            if (diff >= 0 || std::abs(diff) > 3)
                return false;
        }
    }
    return true;
}

bool Day2::checkIfSafeP2(const vector<int> &check)
{
    bool lowToHigh = check[0] < check[1];
    if (checkIfSafe(check))
        return true;

    for (int skipIndex = 0; skipIndex < check.size(); skipIndex++)
    {
        vector<int> modified;
        for (int i = 0; i < check.size(); i++)
        {
            if (i != skipIndex)
            {
                modified.push_back(check[i]);
            }
        }


        if (modified.size() >= 2)
        {
            bool isIncreasing = modified[0] < modified[1];
            if (checkIfSafe(modified))
                return true;
        }
    }
    return false;
}

int Day2::part1()
{
    int result = 0;
    for (const string &str : lines)
    {
        vector<int> nums;
        std::stringstream iss(str);

        int number;

        while (iss >> number)
            nums.push_back(number);

        if (checkIfSafe(nums))
            result++;
    }
    return result;
}

int Day2::part2()
{
    int result = 0;
    for (const string &str : lines)
    {
        vector<int> nums;
        std::stringstream iss(str);

        int number;

        while (iss >> number)
            nums.push_back(number);

        if (checkIfSafeP2(nums))
            result++;
    }
    return result;
}

void Day2::solve()
{
    readFileToArrays("../input.txt");
    cout << "Day 2 Solutions" << endl;
    cout << "Part1: " << part1() << endl;
    cout << "Part2: " << part2() << endl;
}