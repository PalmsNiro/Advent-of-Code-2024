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

bool Day6::frontIsClear(pair<int, int> pos, CardinalDir facingDir)
{
    switch (facingDir)
    {
    case N:
        if (posInBounds(make_pair(pos.first, pos.second - 1)) &&
            map.at(pos.second - 1).at(pos.first) == '#')
            return false;
        return true;

    case E:
        if (posInBounds(make_pair(pos.first + 1, pos.second)) &&
            map.at(pos.second).at(pos.first + 1) == '#')
            return false;
        return true;

    case S:
        if (posInBounds(make_pair(pos.first, pos.second + 1)) &&
            map.at(pos.second + 1).at(pos.first) == '#')
            return false;
        return true;

    case W:
        if (posInBounds(make_pair(pos.first - 1, pos.second)) &&
            map.at(pos.second).at(pos.first - 1) == '#')
            return false;
        return true;
    }
    return false; // Default return
}

bool Day6::posInBounds(pair<int, int> pos)
{
    bool inBounds = pos.second >= 0 &&
                    pos.second < map.size() &&
                    pos.first >= 0 &&
                    pos.first < map[0].length();
    return inBounds;
}

int Day6::part1()
{
    int result = 0;

    pair<int, int> pos; // position of Guard
    // 1. find starting pos;
    int y = 0;
    for (const auto &s : map)
    {
        size_t x = s.find('^');
        if (x != string::npos)
        { 
            pos = {(int)x, y};
            break; 
        }
        y++;
    }


    CardinalDir facingDir = N;
    while (posInBounds(pos))
    {

        while (frontIsClear(pos, facingDir) && posInBounds(pos))
        {
            if (map.at(pos.second).at(pos.first) != 'X')
            {
                map.at(pos.second)[pos.first] = 'X';
                result++;
            }

            switch (facingDir)
            {
            case N:
                pos.second--;
                break; 
            case E:
                pos.first++;
                break; 
            case S:
                pos.second++;
                break; 
            case W:
                pos.first--;
                break; 
            };
        }

        // turn 90 degrees
        switch (facingDir)
        {
        case N:
            facingDir = E;
            break;
        case E:
            facingDir = S;
            break;
        case S:
            facingDir = W;
            break;
        case W:
            facingDir = N;
            break;
        };
    }

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