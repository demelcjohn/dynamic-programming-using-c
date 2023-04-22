// function : allConstruct
// Input : target, wordBank
// Output : Return 2D array containing all of the ways
// that the target can be constructed by concatenating
// elements of wordBank. Each element of 2D array should
// represent one combination that constructs the target
// You may reuse elements of wordbank as many times as
// needed

#include <iostream>
#include <string.h>
#include <vector>
#include <map>

using namespace std;

std::map<std::string, vector<vector<std::string>>> m;

vector<vector<std::string>> allConstruct(std::string target, std::string wordBank[50], int n);

int main()
{
    vector<vector<std::string>> v;
    std::string target = "abcdef";
    std::string wordBank[50] = {"ab", "abc", "cd", "def", "abcd", "ef", "cl"};
    int n = 7;
    v = allConstruct(target, wordBank, n);
    for (vector<std::string> v1 : v)
    {
        for (std::string v2 : v1)
        {
            std::cout << v2 << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

vector<vector<std::string>> allConstruct(std::string target, std::string wordBank[50], int n)
{

    vector<vector<std::string>> result{}, suffixWays, targetWays;
    std::string suffix;
    if (m.find(target) != m.end())
        return m[target];
    if (target == "")
    {
        return vector<vector<std::string>>();
    }
    for (int i = 0; i < n; ++i)
    {
        if (target.find(wordBank[i]) == 0)
        {
            suffix = target.substr(wordBank[i].length());
            suffixWays = allConstruct(suffix, wordBank, n);
            targetWays.insert(targetWays.end(), suffixWays.end(), suffixWays.begin());
            result.insert(result.end(), targetWays.begin(), targetWays.end());
        }
    }
    m[target] = result;
    return result;
}

// error not completed
