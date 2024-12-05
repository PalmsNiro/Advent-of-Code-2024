#include "Day5.hpp"

using namespace std;

Day5::Day5() {};

// Function to split a string into tokens based on a
// delimiter
vector<int> splitString(string &input, char delimiter)
{

    // Creating an input string stream from the input string
    istringstream stream(input);

    // Vector to store the tokens
    vector<int> tokens;

    // Temporary string to store each token
    string token;

    // Read tokens from the string stream separated by the
    // delimiter
    while (getline(stream, token, delimiter))
    {
        // Add the token to the vector of tokens
        tokens.push_back(atoi(token.c_str()));
    }

    // Return the vector of tokens
    return tokens;
}

void Day5::readFileToVectors(const std::string filepath)
{
    std::ifstream file1(filepath);
    if (!file1.is_open())
    {
        cout << "Fehler beim Öffnen der Datei!" << endl;
    }

    bool firstHalf = true;
    string line;
    while (std::getline(file1, line))
    {
        if (line.length())
        {
            if (firstHalf)
            {
                int x = atoi(line.substr(0, line.find('|')).c_str());
                int y = atoi(line.substr(line.find('|') + 1, line.length()).c_str());
                // cout << x << " : " << y << endl;
                pageOrderingRules.push_back(std::make_pair(x, y));
            }
            else
            {
                pageNumbers.push_back(splitString(line, ','));
                // printVector(splitString(line, ','));
            }
        }
        else
        {
            firstHalf = false;
        }
    }
    file1.close();
}

int Day5::part1()
{
    int result = 0;

    // loop over pageNumbers
    for (const auto &pnv : pageNumbers)
    {
        bool valid = true;

        for (const auto &rules : pageOrderingRules)
        {
            bool containsRules = find(pnv.begin(), pnv.end(), rules.first) != pnv.end() && std::find(pnv.begin(), pnv.end(), rules.second) != pnv.end();
            if (containsRules)
            {
                // if rules are not satisfied set valid to false && break
                auto posxIt = find(pnv.begin(), pnv.end(), rules.first);
                auto posyIt = find(pnv.begin(), pnv.end(), rules.second);
                int posX = posxIt - pnv.begin();
                int posY = posyIt - pnv.begin();

                if (posX > posY)
                    valid = false;
            }
        }
        if (valid)
        {
            result += pnv.at(pnv.size()/2);
        }
    }

    return result;
}

int Day5::part2() { return 1; }

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