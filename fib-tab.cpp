// Tabulation
// function fib(n)
// Input number n
// Output: nth number of fibonacci sequence

#include <iostream>
#include <vector>

using namespace std;

int fib(int n);

int main()
{
    int n, f;
    printf("Fibonacci : ");
    scanf("%d", &n);
    f = fib(n);
    printf("\n%d\n", f);
    return 0;
}

int fib(int n)
{
    vector<int> table;
    for (int i = 0; i < n + 1; ++i)
    {
        table.push_back(0);
    }
    table[1] = 1;
    for (int i = 0; i <= n; ++i)
    {
        table[i + 1] += table[i];
        table[i + 2] += table[i];
    }
    return table[n];
}