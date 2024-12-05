#include "Day5.hpp"

using namespace std;

Day5::Day5() {};

void readFileToVectors(const std::string filepath)
{
    std::ifstream file1(filepath);
    if (!file1.is_open())
    {
        cout << "Fehler beim Öffnen der Datei!" << endl;
    }

    string line;
    while (std::getline(file1, line))
    {
        
        
    }
    file1.close();
}

int Day5::part1() {}

int Day5::part2() {}

void Day5::solve()
{
    readFileToVectors("../input.txt");
    // cout << text << endl;
    cout << "Day 5 Solutions" << endl;
    cout << "Part1: " << endl
         << part1() << endl;
    // cout << "Part2: " << endl
    //  << part2() << endl;
}