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

int multiply(smatch match)
{
    string mul = match[0];
    mul.replace(0, 4, "");
    mul.replace(mul.end() - 1, mul.end(), "");
    replace(mul.begin(), mul.end(), ',', ' ');
    // cout << mul << endl;
    int ln = atoi(mul.substr(0, mul.find(' ')).c_str());
    int rn = atoi(mul.substr(mul.find(' '), mul.length()).c_str());
    cout << ln << " : " << rn << endl;
    return ln * rn;
}

int Day3::part1()
{
    int result = 0;

    regex pattern("mul\\((\\d*)\\,(\\d*)\\)");
    std::smatch match;

    while (regex_search(text, match, pattern))
    {
        result += multiply(match);
        text = match.suffix();
    }

    return result;
}

int Day3::part2()
{
    int result = 0;
    bool notFinished = true;
    bool enabled = true;

    regex mulPattern("mul\\((\\d*)\\,(\\d*)\\)");
    regex doPattern("do\\(\\)");
    regex dontPattern("don't\\(\\)");

    int iteration = 1;
    string remaining = text;
    while (!remaining.empty())
    {
        smatch matchMul, matchDo, matchDont;

        bool hasMul = regex_search(remaining, matchMul, mulPattern);
        bool hasDo = regex_search(remaining, matchDo, doPattern);
        bool hasDont = regex_search(remaining, matchDont, dontPattern);

        if (!hasMul && !hasDo && !hasDont)
            break;

        // Finde den nächstgelegenen Match
        size_t mulPos = hasMul ? matchMul.position() : string::npos;
        size_t doPos = hasDo ? matchDo.position() : string::npos;
        size_t dontPos = hasDont ? matchDont.position() : string::npos;

        // Handle den nächsten Match
        if (hasMul && (!hasDo || mulPos < doPos) && (!hasDont || mulPos < dontPos))
        {
            if (enabled)
            {
                result += multiply(matchMul);
            }
            remaining = remaining.substr(mulPos + matchMul.length());
        }
        else if (hasDo && (!hasDont || doPos < dontPos))
        {
            enabled = true;
            remaining = remaining.substr(doPos + matchDo.length());
        }
        else if (hasDont)
        {
            enabled = false;
            remaining = remaining.substr(dontPos + matchDont.length());
        }
    }

    return result;
}

void Day3::solve()
{
    readFileToString("../input.txt");
    // cout << text << endl;
    cout << "Day 3 Solutions" << endl;
    // cout << "Part1: " << endl
    //      << part1() << endl;
    cout << "Part2: " << endl
         << part2() << endl;
}