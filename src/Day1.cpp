#include "Day1.hpp"

using std::cout;
using std::endl;
using std::sort;
using std::string;
using std::vector;

Day1::Day1() {};

void Day1::readFileToArrays(const string filepath)
{
    std::ifstream file1(filepath);
    if (!file1.is_open())
    {
        cout << "Fehler beim Öffnen der Datei!" << endl;
    }

    string line;
    while (std::getline(file1, line))
    {
        // erase whitespaces
        line.erase(remove_if(line.begin(), line.end(), isspace), line.end());
        // split string in middle
        int firsthalf = std::stoi(line.substr(0, 5));
        int secondhalf = std::stoi(line.substr(5, 5));
        // put each half in their respected array
        arr1.push_back(firsthalf);
        arr2.push_back(secondhalf);
    }
    file1.close();
}

void Day1::sortArrays()
{
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}

int Day1::part1()
{
    sortArrays();
    int result = 0;
    for (int i = 0; i < arr1.size(); i++)
    {
        result += std::abs(arr1[i] - arr2[i]);
    }

    return result;
}

int Day1::part2()
{
    int result = 0;
    std::unordered_map<int, int> alreadyChecked;
    for (int i : arr1)
    {
        if (alreadyChecked.find(i) == alreadyChecked.end()) // key not present in map
        {
            int simScore = std::count(arr2.begin(), arr2.end(), i);
            alreadyChecked.insert({i, simScore});
            result += i * simScore;
        }
        else // key present in map
        {
            result += i * alreadyChecked[i];
        }
    }
    return result;
}

void Day1::solve()
{
    readFileToArrays("../input.txt");
    cout << "Day 1 Solutions" << endl;
    cout << "Part1: " << part1() << endl;
    cout << "Part2: " << part2() << endl;
}