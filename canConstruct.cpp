// Write a function 'canConstruct(target, wordBank)' that
// accepts a target string and an array of strings.
// Output: Boolean indicating whether or not the 'target'
// can be constructed by concatenating elements of the
//'wordBank' array
// Reuse of elements of 'wordBank' is possible

#include <iostream>
#include <string.h>
// #include <map>

using namespace std;

// std::map<int, int> m;

int canConstruct(std::string target, std::string wordBank[50], int n);

int main()
{
    int v;
    std::string target = "skateboard";
    std::string wordBank[50] = {"bo", "rd", "ate", "t", "ska", "sk", "boar"};
    int n = 7;
    v = canConstruct(target, wordBank, n);
    std::cout << v << std::endl;
    return 0;
}

int canConstruct(std::string target, std::string wordBank[50], int n)
{
    std::string suffix;
    if (target == "")
    {
        return 1;
    }
    for (int i = 0; i < n; ++i)
    {
        if (target.find(wordBank[i]) == 0)
        {
            suffix = target.substr(wordBank[i].length());
            if (canConstruct(suffix, wordBank, n) == 1)
            {
                return 1;
            }
        }
    }
    return 0;
}
