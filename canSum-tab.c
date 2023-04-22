// Input : Target sum and array of numbers
// Output : Boolean , whether it is possible to generate
// target sum using numbers from array

#include <stdio.h>
#include <stdlib.h>

int canSum(int targetSum, int nums[25], int n)
{
    int val;
    int *table = (int *)malloc(sizeof(int) * (targetSum + 1));
    for (int i = 0; i <= targetSum; ++i)
    {
        table[i] = 0;
    }
    table[0] = 1;
    for (int i = 0; i <= targetSum; ++i)
    {
        if (table[i] == 1)
        {
            for (int j = 0; j < n; ++j)
            {
                table[i + nums[j]] = 1;
            }
        }
    }
    // val = table[targetSum];
    // free(table);
    // return val;
    return table[targetSum];
}

int main()
{
    int nums[25], targetSum, n, c;
    printf("Target sum: ");
    scanf("%d", &targetSum);
    printf("Size of array : ");
    scanf("%d", &n);
    printf("Enter the array : ");
    for (int i = 0; i < n; ++i)
        scanf("%d", &nums[i]);
    c = canSum(targetSum, nums, n);
    printf("%d\n", c);
    return 0;
}
