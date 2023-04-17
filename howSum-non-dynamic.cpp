// function howSum(targetSum, numbers)
// Input: targetSum, array numbers[]
// Output: An array containing any combination of
// elements that add up to exactly the targetSum.
// If no combination that adds up to the targetSum,
// then return null. If many return any.

#include <iostream>
#include <vector>

using namespace std;

vector<int> howSum(int targetSum, int a[], int);

void display(vector<int> v);

int main()
{
    vector<int> v;
    int a[] = {2, 4};
    int n = 2;
    v = howSum(7, a, n);
    display(v);
    v.clear();
    return 0;
}

vector<int> howSum(int targetSum, int a[], int n)
{
    vector<int> remainderResult{};
    int remainder;
    if (targetSum == 0)
        return vector<int>();
    if (targetSum < 0)
        return {-1};
    for (int i = 0; i < n; ++i)
    {

        remainder = targetSum - a[i];
        remainderResult = howSum(remainder, a, n);
        if (remainderResult.empty())
        {
            remainderResult.push_back(a[i]);
            return remainderResult;
        }
        else if (remainderResult[0] != -1)
        {
            remainderResult.push_back(a[i]);
            return remainderResult;
        }
    }
    return {-1};
}

void display(vector<int> v)
{
    for (int i : v)
        cout << i << " ";
    cout << endl;
}