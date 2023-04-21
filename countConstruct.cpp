// function 'countConstruct(target, wordBank)' that accepts a
// target string and an array of strings.
// Output: Return number of ways that the target can be constructed
// by concatenating elements of the wordBank array
// Reuse of wordBank elements are possible

#include <iostream>
#include <string.h>
#include <map>

using namespace std;

std::map<std::string, int> m;

int countConstruct(std::string target, std::string wordBank[50], int n);

int main()
{
    int v;
    std::string target = "enterapotentpot";
    std::string wordBank[50] = {"a", "p", "ent", "enter", "ot", "o", "t"};
    int n = 7;
    v = countConstruct(target, wordBank, n);
    std::cout << v << std::endl;
    return 0;
}

int countConstruct(std::string target, std::string wordBank[50], int n)
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
            numWaysForRest = countConstruct(suffix, wordBank, n);
            totalCount += numWaysForRest;
        }
    }
    m[target] = totalCount;
    return totalCount;
}

// Time : O(n*m^2)
