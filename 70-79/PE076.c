#include <stdio.h>

int main()
{

    int target = 100;
    int ways[101];
    ways[0] = 1;

    for (int i = 1; i <= 99; i++)
    {
        for (int j = i; j <= target; j++)
        {
            ways[j] += ways[j - i];
        }
    }

    printf("%d", ways[100]);
    return 0;
}