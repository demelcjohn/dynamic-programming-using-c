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

std::map<std::string, int> m;

int allConstruct(std::string target, std::string wordBank[50], int n);

int main()
{
    int v;
    std::string target = "abcdef";
    std::string wordBank[50] = {"ab", "abc", "cd", "def", "abcd", "ef", "cl"};
    int n = 7;
    v = allConstruct(target, wordBank, n);
    std::cout << v << std::endl;
    return 0;
}

int allConstruct(std::string target, std::string wordBank[50], int n)
{
    std::string suffix;
    int totalCount = 0, numWaysForRest;
    if (m.find(target) != m.end())
        return m[target];
    if (target == "")
    {
        return 1;
    }
    for (int i = 0; i < n; ++i)
    {
        if (target.find(wordBank[i]) == 0)
        {
            suffix = target.substr(wordBank[i].length());
            numWaysForRest = allConstruct(suffix, wordBank, n);
            totalCount += numWaysForRest;
        }
    }
    m[target] = totalCount;
    return totalCount;
}
