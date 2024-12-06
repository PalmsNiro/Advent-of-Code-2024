#include "Day6.hpp"

using namespace std;

Day6::Day6() {};

void Day6::readFileToMapVec(const std::string filepath)
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
        map.push_back(line);
    }
    file1.close();
}

int Day6::part1()
{
    int result = 0;
    // 1. find starting pos;
    pair<int, int> startPos;
    for (const auto &s : map)
    {
        int y = 0;
        if (s.find('^'))
        {
            startPos = {s.find('^'), y};
        }
        y++;
    }
    cout << startPos.first << " : " << startPos.second << endl;

    return result;
}
int Day6::part2()
{
    int result = 0;

    return result;
}


void Day6::solve()
{
    readFileToMapVec("../input.txt");
    // cout << text << endl;
    cout << "Day 6 Solutions" << endl;
    cout << "Part1: " << endl
         << part1() << endl;
    // cout << "Part2: " << endl
    //  << part2() << endl;
}