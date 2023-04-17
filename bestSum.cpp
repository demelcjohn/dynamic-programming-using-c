// bestSum(targetSum, numbers)
// Input: targetSum, array of arguments
// Output: An array with shortest combination
// of numbers that add up to exactly the targetSum.
// Return any if many.

#include <iostream>
#include <vector>
#include <map>

using namespace std;

std::map<int, std::vector<int>> m;

vector<int> bestSum(int targetSum, int a[], int);

void display(vector<int> v);

int main()
{
    vector<int> v;
    int a[] = {1, 2, 5, 25};
    int n = 4;
    v = bestSum(100, a, n);
    display(v);
    v.clear();
    return 0;
}

vector<int> bestSum(int targetSum, int a[], int n)
{
    vector<int> shortestCombination = {-1}, remainderCombination;
    vector<int> combination;
    int remainder;
    if (m.find(targetSum) != m.end())
        return m[targetSum];
    if (targetSum == 0)
        return vector<int>();
    if (targetSum < 0)
        return {-1};
    for (int i = 0; i < n; ++i)
    {

        remainder = targetSum - a[i];
        remainderCombination = bestSum(remainder, a, n);
        if (remainderCombination.empty())
        {
            combination = remainderCombination;
            combination.push_back(a[i]);
            if (shortestCombination[0] == -1 || (combination.size() != 0 && combination.size() < shortestCombination.size()))
                shortestCombination = combination;
        }
        else if (remainderCombination[0] != -1)
        {
            combination = remainderCombination;
            combination.push_back(a[i]);
            if (shortestCombination[0] == -1 || (combination.size() != 0 && combination.size() < shortestCombination.size()))
                shortestCombination = combination;
        }
    }
    m[targetSum] = shortestCombination;
    return shortestCombination;
}

void display(vector<int> v)
{
    for (int i : v)
        cout << i << " ";
    cout << endl;
}

// time : O(m^2*n)
