// function howSum(targetSum, numbers)
// Input: targetSum, array numbers[]
// Output: An array containing any combination of
// elements that add up to exactly the targetSum.
// If no combination that adds up to the targetSum,
// then return null. If many return any.

#include <iostream>
#include <vector>

using namespace std;

vector<int> howSum(int targetSum, int a[]);

void display(vector<int> v);

int main()
{
    vector<int> v;
    int a[] = {1, 2, 3};
    v = howSum(7, a);
    display(v);
    v.clear();
    return 0;
}

vector<int> howSum(int targetSum, int a[])
{
}

void display(vector<int> v)
{
    for (int i : v)
        cout << i << " ";
    cout << endl;
}