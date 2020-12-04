#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

long data[80][80];

void readData() {

    FILE *fp;
    fp = fopen("matrix.txt", "r");

    long dataPoint;

    for (int i = 0; i < 80; i++) {
        for (int j = 0; j < 80; j++) {
            fscanf(fp, "%d", &dataPoint);
            data[i][j] = dataPoint;
        }
    }
    fclose(fp);
}

long min2(long a, long b) { return a < b ? a : b; }

long min3(long a, long b, long c) {
    if (a > b)
        return a < c ? a : c;
    else
        return b < c ? b : c;
}

void outputData() {

    FILE *fp;
    fp = fopen("matrix.out", "w");

    for (int i = 0; i < 80; i++) {
        for (int j = 0; j < 80; j++) {
            fprintf(fp, "%6d ", data[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

int main() {
    system("cls");
    readData();

    // for (int i = 0; i < 80; i++) {
    //     for (int j = 0; j < 80; j++) {
    //         printf("%4d ", data[i][j]);
    //     }
    //     printf("\n");
    // }


    for (int i = 0; i < 80; i++) {
        for (int j = 1; j < 80; j++) {
            if (i == 0)
                data[i][j] += min2(data[i + 1][j], data[i][j - 1]);
            else if (i == 79)
                data[i][j] += min2(data[i - 1][j], data[i][j - 1]);
            else
                data[i][j] +=
                    min3(data[i - 1][j], data[i + 1][j], data[i][j - 1]);
        }
    }

    long smallest = INT_MAX;
    for (int i = 0; i < 80; i++) {
        smallest = min2(smallest, data[i][79]);
    }

    printf("Smallest: %d\n", smallest);

    outputData();

    return 0;
}