#include <stdio.h>

int f(int i, int j, int coins[])
{

    // printf("i: %d, j: %d\n", i, j);

    if (j == 0)
        return 1;

    if (coins[j] > i)
        return f(i, j - 1, coins);

    return f(i, j - 1, coins) + f(i - coins[j], j, coins);

    return -1000;
}

int main()
{

    int coins[8];
    coins[0] = 1;
    coins[1] = 2;
    coins[2] = 5;
    coins[3] = 10;
    coins[4] = 20;
    coins[5] = 50;
    coins[6] = 100;
    coins[7] = 200;

    printf("   ");
    for (int i = 1; i <= 10; i++)
        printf("  %d ", i);

    printf("\n");

    for (int j = 0; j <= 3; j++)
    {
        for (int i = 1; i <= 10; i++)
        {
            if (i == 1)
                printf("%d:  ", j);

            printf(" %d, ", f(i, j, coins));
        }
        printf("\n");
    }

    printf("%d", f(200, 7, coins));
    return 0;
}