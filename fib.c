// write a function that takes in a number as an argument.
// The function should return the nth number of fibonacci sequence.

// memorization

#include <stdio.h>

int cache[100] = {0, 1, 1}, c = 3;
int fib(int n)
{
    if (n < c)
        return cache[n];
    if (n <= 2)
        return 1;
    cache[n] = fib(n - 1) + fib(n - 2);
    c++;
    return cache[n];
}

void main()
{
    int n, f;
    printf("Fibonacci : ");
    scanf("%d", &n);
    f = fib(n);
    printf("\n%d\n", f);
}