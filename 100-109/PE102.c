#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int data[1000][3][2];

void readData() {

    FILE *fp;
    fp = fopen("triangles.txt", "r");

    int dataPoint;

    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 2; k++) {
                fscanf(fp, "%d", &dataPoint);
                data[i][j][k] = dataPoint;
            }
        }
    }

    fclose(fp);
}

double getArea(int a[2], int b[2], int c[2]) {

    double area = (a[0] - c[0]) * (b[1] - a[1]) - (a[0] - b[0]) * (c[1] - a[1]);
    return abs(area);
}

bool containsOrigin(int tri[3][2]) {

    int *a = tri[0];
    int *b = tri[1];
    int *c = tri[2];

    // printTriangle(tri);

    int origin[2] = {0, 0};

    double origArea = getArea(a, b, c);

    double a1 = getArea(a, b, origin);
    double a2 = getArea(a, origin, c);
    double a3 = getArea(origin, b, c);

    double totalArea = a1 + a2 + a3;

    // printf("%.2lf, %.2lf\n", totalArea, origArea);

    return totalArea == origArea;
}

void printTriangle(int arr[3][2]) {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d, ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {

    readData();

    int total = 0;

    for (int i = 0; i < 1000; i++) {
        if (containsOrigin(data[i]))
            total++;
    }

    printf("Total: %d", total);

    return 0;
}