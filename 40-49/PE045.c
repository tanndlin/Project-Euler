#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isPentagonal(int number)
{
    double penTest = (sqrt(1 + 24 * number) + 1.0) / 6.0;
    printf("%.2f\n", penTest);
    return penTest == ((int)penTest);
}

int main()
{

    long result = 0;
    int i = 143;

    while (true)
    {
        i++;
        result = i * (2 * i - 1);

        if (isPentagonal(result))
        {
            break;
        }
    }

    printf("%d"), result;

    return 0;
}