#include <stdio.h>
#include <stdlib.h>
// Bubble sort
void sort(double[], int);

// Get the average from allData[49] to allData[149]
double getAverage(double[], int);

// Add the data to the first and delete last data
void addData(double[], int, int);

// Main function
int main() {
    double allData[200] = {0};
    double data;
    while(scanf("%lf", &data)==1) {
        addData(allData, 200, data);
        printf("%lf ", getAverage(allData, 200));
    }
    return 0;
}

void sort(double allData[], int size) {
    for(int i=0; i<size-1; i++) {
        for(int j=size-1; j>i; j--) {
            if(allData[j]<allData[j-1]) {
                double temp = allData[j];
                allData[j] = allData[j-1];
                allData[j-1] = temp;
            }
        }
    }
}

double getAverage(double allData[], int size) {
    double *clonedAllData = (double*) malloc(sizeof(double)*size);
    for(int i=0;i<size;i++) clonedAllData[i] = 0;
    for(int i=0; i<size; i++) {
        clonedAllData[i] = allData[i];
    }
    
    sort(clonedAllData, size);
    double total = 0;
    for(int i=50; i<=149; i++) {
        total += clonedAllData[i];
    }
    return total/100;
}

void addData(double allData[], int size, int data) {
    for(int i=size-1; i>0; i--) {
        allData[i] = allData[i-1];
    }
    allData[0] = data;
}
