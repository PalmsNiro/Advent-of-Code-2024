#include "Day3.hpp"
#include <regex>
#include <sstream>

using namespace std;

// const regex str_expr("mul\((\d*)\,(\d*)\)");

Day3::Day3() {};

void Day3::readFileToString(const string filepath)
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
        text.append(line);
    }
    file1.close();
}

int Day3::part1()
{
    int result = 0;

    regex pattern("mul\\((\\d*)\\,(\\d*)\\)");
    std::smatch match;

    while (regex_search(text, match, pattern))
    {
        cout << "Found: " << match[0] << std::endl;
        string mul = match[0];
        mul.replace(0, 4, "");
        mul.replace(mul.end() - 1, mul.end(), "");
        replace(mul.begin(), mul.end(), ',', ' ');
        // cout << mul << endl;
        int ln = atoi(mul.substr(0, mul.find(' ')).c_str());
        int rn = atoi(mul.substr(mul.find(' '), mul.length()).c_str());
        cout << ln << " : " << rn << endl;
        result += ln * rn;
        text = match.suffix();
    }

    return result;
}

int Day3::part2()
{
    int result = 0;
    bool enabled = true;

    regex mulPattern("mul\\((\\d*)\\,(\\d*)\\)");
    regex doPattern("do\\(\\)");
    regex dontPattern("don't\\(\\)");
    std::smatch match;

    while (regex_search(text, match, dontPattern))
    {
        cout << "Found: " << match[0] << std::endl;

        text = match.suffix();
    }

    return result;
}

void Day3::solve()
{
    readFileToString("../input.txt");
    // cout << text << endl;
    cout << "Day 2 Solutions" << endl;
    // cout << "Part1: " << endl
    //      << part1() << endl;
    cout << "Part2: " << endl
         << part2() << endl;
}