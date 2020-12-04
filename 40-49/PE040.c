#include <stdio.h>
#include <string.h>

int getLength(int i)
{
    return (int)((ceil(log10(i)) + 1));
}

int main()
{

    char string[5];

    for (int i = 1; i <= 5; i++)
    {
        char temp[12];
        strcat(string, itoa(i, temp,10));
    }
    
    printf("%s", string);

    return 0;
}