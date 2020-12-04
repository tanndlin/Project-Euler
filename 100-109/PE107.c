#include <stdio.h>

int data[40][40];
int newGrid[40][40];

void readData() {

    FILE *fp;
    fp = fopen("network.txt", "r");
    int dataPoint;

    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < 40; j++) {
            fscanf(fp, "%d ", &dataPoint);
            data[i][j] = dataPoint;
        }
    }

    fclose(fp);
}

void printGrid() {
    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < 40; j++) {
            printf("%3d ", data[i][j]);
        }
        printf("\n");
    }
}

int createsCycle(int startingPoint) {
    int visited[40];
    for (int i = 0; i < 40; i++)
        visited[i] = 0;

    visited[startingPoint] = 1;
    int current = startingPoint;
    
    

    //Trace

}

int main() {
    readData();
    printGrid();

    return 0;
}