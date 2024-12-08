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
    // cout << "Checking bounds for pos " << pos.first << "," << pos.second << endl;
    // cout << "Map size: " << map.size() << "x" << map[0].length() << endl;

    bool inBounds = pos.second >= 0 &&
                    pos.second < map.size() &&
                    pos.first >= 0 &&
                    pos.first < map[0].length();

    // cout << "Position is " << (inBounds ? "in" : "out of") << " bounds" << endl;
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
        { // Korrekter Vergleich
            pos = {(int)x, y};
            break; // Optional: Wenn wir den Startpunkt gefunden haben, können wir die Schleife verlassen
        }
        y++;
    }
    // cout << "starting pos: " << pos.first << " : " << pos.second << endl;

    CardinalDir facingDir = N;
    while (posInBounds(pos))
    {

        while (frontIsClear(pos, facingDir) && posInBounds(pos))
        {
            // cout << "front clear" << endl;
            if (map.at(pos.second).at(pos.first) != 'X')
            {
                map.at(pos.second)[pos.first] = 'X';
                result++;
            }

            switch (facingDir)
            {
            case N:
                pos.second--;
                break; // break hinzugefügt
            case E:
                pos.first++;
                break; // break hinzugefügt
            case S:
                pos.second++;
                break; // break hinzugefügt
            case W:
                pos.first--;
                break; // break hinzugefügt
            };
            // cout << "Pos: " << pos.first << " : " << pos.second << endl;
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
        // cout << "Pos: " << pos.first << " : " << pos.second << endl;
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