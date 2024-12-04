#include "Day4.hpp"

using namespace std;

Day4::Day4() {};

void Day4::readFileToString(const std::string filepath)
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
        textVec.push_back(line);
    }
    file1.close();
}

int Day4::checkDirections(int indexLine, int indexChar)
{
    int xmasAmount = 0;

    string top;
    string right;
    string bottom;
    string left;
    string topLeft;
    string topRight;
    string bottomRight;
    string bottomLeft;

    int horizontalLength = textVec.at(0).length() - 1;
    int vertLength = textVec.size() - 1;

    for (int i = 0; i < 4; i++)
    {
        // top
        if (indexLine - i >= 0)
            top.insert(top.end(), textVec.at(indexLine - i).at(indexChar));
        // right
        if (indexChar + i <= horizontalLength)
            right.insert(right.end(), textVec.at(indexLine).at(indexChar + i));
        // bottom
        if (indexLine + i <= vertLength)
            bottom.insert(bottom.end(), textVec.at(indexLine + i).at(indexChar));
        // left
        if (indexChar - i >= 0)
            left.insert(left.end(), textVec.at(indexLine).at(indexChar - i));

        // topLeft
        if (indexLine - i >= 0 && indexChar - i >= 0)
            topLeft.insert(topLeft.end(), textVec.at(indexLine - i).at(indexChar - i));
        // topRight
        if (indexLine - i >= 0 && indexChar + i <= horizontalLength)
            topRight.insert(topRight.end(), textVec.at(indexLine - i).at(indexChar + i));
        // bottomRight
        if (indexLine + i <= vertLength && indexChar + i <= horizontalLength)
            bottomRight.insert(bottomRight.end(), textVec.at(indexLine + i).at(indexChar + i));
        // bottomLeft
        if (indexLine + i <= vertLength && indexChar - i >= 0)
            bottomLeft.insert(bottomLeft.end(), textVec.at(indexLine + i).at(indexChar - i));
    }
    vector<string> words = {top, right, bottom, left, topLeft, topRight, bottomRight, bottomLeft};
    for (const auto &w : words)
        if (w == "XMAS")
            xmasAmount++;

    return xmasAmount;
}

int Day4::part1()
{
    int result = 0;
    // iterate through each Line
    // In each Line iterate through all chars
    // check if char is X => check all directions for word
    int lineInd = 0;
    for (auto line : textVec)
    {
        int charInd = 0;
        for (char c : line)
        {
            if (c == 'X')
            {
                result += checkDirections(lineInd, charInd);
            }
            charInd++;
        }
        lineInd++;
    }
    return result;
}

int Day4::part2() { return 0; }

void Day4::solve()
{
    readFileToString("../input.txt");
    // cout << text << endl;
    cout << "Day 4 Solutions" << endl;
    cout << "Part1: " << endl
         << part1() << endl;
    // cout << "Part2: " << endl
    //  << part2() << endl;
}