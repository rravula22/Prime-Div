#include <string.h>

int min, max, indexMin, indexMax, arrayCount;
float mean;
char *ops[] = { "minValue", "maxValue", "indexMin", "indexMax", "mean"};

void readArray(int *arr, int s) {
    printf("\n Enter the array of integers: \n");
    for(int i =0; i < s; i++) {
        scanf("%d", &arr[i]);
    }
}

void findValues(int *arr, int s) {
    min = max = arr[0];
    indexMin = indexMax = 0;
    arrayCount = 0;
    for (int i = 1; i < s; i++) {
        if(arr[i] < min) {
            min = arr[i];
            indexMin = i;
        }
        if(arr[i] > max) {
            max = arr[i];
            indexMax = i;
        }
        arrayCount += arr[i];
        mean = arrayCount / s;
    }
}

int returnValues(char f[]) {
    if(strcmp(f, ops[2]) == 0) return indexMin;
    if(strcmp(f, ops[0]) == 0) return min;
    if(strcmp(f, ops[1]) == 0) return max;
    if(strcmp(f, ops[3]) == 0) return indexMax;
    if(strcmp(f, ops[4]) == 0) return mean;
    return 0;
}