// Say that you are a traveler on a 2D grid. You begin in the
// top-left corner and your goal is to travel to the bottom-right
// corner. You may only move down or right.

// In how many ways can you travel to the goal on a grid with
// dimensions m*n?

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int gridTraveler(int m, int n)
{
    std::map<std::pair<int, int>, int> table;
    int current;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            table[{i, j}] = 0;
        }
    }

    table[{1, 1}] = 1;
    for (int i = 0; i <= m; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            current = table[{i, j}];
            if (j + 1 <= n)
                table[{i, j + 1}] += current;
            if (i + 1 <= m)
                table[{i + 1, j}] += current;
        }
    }
    return table[{m, n}];
}

int main()
{
    int m, n, moves;
    moves = gridTraveler(3, 3);
    std::cout << moves << std::endl;
    return 0;
}