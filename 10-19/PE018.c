#include <stdio.h>

int data[15][15];

void readData() {

    FILE *fp;
    fp = fopen("PE018 Data.txt", "r");

    int dataPoint;

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j <= i; j++) {
            fscanf(fp, "%d", &dataPoint);
            data[i][j] = dataPoint;
        }
    }

    fclose(fp);
}

int max(int a, int b) { return a > b ? a : b; }

int main() {

    readData();

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%2d ", data[i][j]);
        }
        printf("\n");
    }

    for (int i = 1; i < 15; i++) {
        for (int j = 0; j <= i; j++) {

            if (j == 0)
                data[i][j] += data[i - 1][j];
            else if (j == i)
                data[i][j] += data[i - 1][j - 1];
            else
                data[i][j] += max(data[i - 1][j - 1], data[i - 1][j]);
        }
    }

    int largest = 0;
    for (int i = 0; i < 15; i++) {
        largest = max(largest, data[14][i]);
    }

    printf("%d", largest);

    return 0;
}