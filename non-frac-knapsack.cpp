// 0/1 Knapsack

// We are given N items where each item has some weight
// and profit associated with it. We are also given a
// bag with capacity W, [i.e., the bag can hold at most
// W weight in it]. The target is to put the items into
// the bag such that the sum of profits associated with
// them is the maximum possible.

// Note: The constraint here is we can either put an
// item completely into the bag or cannot put it at all
// [It is not possible to put a part of an item into
// the bag].

#include <iostream>
#include <map>

using namespace std;

int knapSack(int, int[], int[], int);

int main()
{
    int profit[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(profit) / sizeof(profit[0]);
    cout << knapSack(W, weight, profit, n);
    return 0;
}

int knapSack(int W, int wt[], int val[], int n)
{
    if (n == 0 || W == 0)
        return 0;

    else if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);

    else
    {
        int max, a, b;
        if ((a = val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1)) > (b = knapSack(W, wt, val, n - 1)))
            max = a;
        else
            max = b;
        return max;
    }
}