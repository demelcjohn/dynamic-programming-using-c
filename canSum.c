// Input : Target sum and array of numbers
// Output : Boolean , whether it is possible to generate
// target sum using numbers from array

#include <stdio.h>

int cache[1000];

int canSum(int targetSum, int nums[25], int n)
{
    if (cache[targetSum] != -1)
        return cache[targetSum];
    int remainder;
    if (targetSum == 0)
        return 1;
    if (targetSum < 0)
        return 0;
    for (int i = 0; i < n; ++i)
    {
        remainder = targetSum - nums[i];
        if (canSum(remainder, nums, n) == 1)
        {
            cache[targetSum] = 1;
            return 1;
        }
    }
    cache[targetSum] = 0;
    return 0;
}

void main()
{
    int nums[25], targetSum, n, c;
    for (int i = 0; i < 1000; ++i)
        cache[i] = -1;
    printf("Target sum: ");
    scanf("%d", &targetSum);
    printf("Size of array : ");
    scanf("%d", &n);
    printf("Enter the array : ");
    for (int i = 0; i < n; ++i)
        scanf("%d", &nums[i]);
    c = canSum(targetSum, nums, n);
    printf("%d\n", c);
}
