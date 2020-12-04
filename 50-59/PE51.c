#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int n) {

    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return 0;
    return 1;
}

char *numToString(int n) {
    int numLength = log10(n)+1;
    char s[128];
    for (int i = 0; i < 128 && n != 0; i++) {
        s[i] = (n % 10) + '0';
        printf("%c\n", s[i]);
        n /= 10;
    }

    char *reversed = malloc(sizeof(char) * numLength);

    for(int i = 0; i < 5; i++){
        reversed[i] = s[4-i];
    }

    return reversed;
}


int main() {

    printf("Hello\n");
    printf("%s\n", numToString(56003));
    printf("Test\n");

    return 0;
}