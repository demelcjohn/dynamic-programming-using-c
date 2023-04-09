// Say that you are a traveler on a 2D grid. You begin in the
// top-left corner and your goal is to travel to the bottom-right
// corner. You may only move down or right.

// In how many ways can you travel to the goal on a grid with
// dimensions m*n?

#include <stdio.h>

int cache[100][100];

int gridTraveler(int m, int n)
{
    if (cache[m][n] != -1)
        return cache[m][n];
    if (m == 1 && n == 1)
        return 1;
    if (m == 0 || n == 0)
        return 0;
    cache[m][n] = gridTraveler(m - 1, n) + gridTraveler(m, n - 1);
    cache[n][m] = cache[m][n];
    return cache[m][n];
}

void main()
{
    int m, n, moves;
    for (int i = 0; i < 25; ++i)
        for (int j = 0; j < 25; ++j)
            cache[i][j] = -1;
    scanf("%d", &m);
    scanf("%d", &n);
    moves = gridTraveler(m, n);
    printf("%d", moves);
}