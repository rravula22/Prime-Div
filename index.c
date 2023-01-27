#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "prime.h"
#include "arrayOperations.h"

//defining the constants
#define l3 "CS"
#define l5 "UAB"
#define l35 "UAB CS 332&532"
#define l0 "GO BLazers"

/**
 * UABNumber : validates the given number whether it is sum of it"s prime divisors.
 * params: (t)->integer
*/
int UABNumber(int t) {
    int sum = 0;
    for(int i = 1; i <= t/2; i++) {
        if(t % i == 0) {
            sum+= i;
        }
    } 
    if (t == sum) return 1;
    return 0;
}

/**
 * intro332532 : generates the string based in the given number
 * params: (n)->integer
*/
void intro332532(int n) {
    double l_3 = n % 3;
    double l_5 = n % 5;
    char *buffer = (char *) malloc(16);
    if (checkIfPrime(n)) printf("%s", l0);
    else if(!l_3 && !l_5) printf("%s", l35);
    else if(!l_3) printf("%s", l3);
    else if(!l_5) printf("%s", l5);
    else printf("%d", n*n*n);
}

/**
 * reverseNum : generates the reversed integer for the given integer
 * params: (t)->integer
*/
int reverseNum(int t) {
    int res = 0;
    while(t > 0) {
        res *= 10;
        res += t % 10;
        t = t / 10;
    }
    return res;
}

/**
 * smallerThanIndex: finding the count of array numbers having value less than it"s index.
*/
int smallerThanIndex(int *t, int s) {
    int count = 0;
    for(int c = 0; c < s; c++) {
        if(t[c] < c) count++;
    }
    return count;
}

/**
 * arrayDetails: finding the array details
*/
int * arrayDetails(int *list, int s) {
    // new array creation using malloc
    int *res =(int *)malloc(6 * sizeof(int));
    findValues(list, s);
    // size
    res[0] = s;
    //minimum of the array
    res[1] = returnValues("minValue");
    res[2] = returnValues("indexMin");
    res[3] = returnValues("mean");
    res[4] = returnValues("maxValue");
    res[5] = returnValues("indexMax");

    return res;
}

int main() {
    int n1, n2, n3, size;
    printf("/*********\t intro332532 \t **********/\n");
    printf("Enter number:");
    scanf("%d", &n1);
    intro332532(n1);

    printf("\n/*********\t UABNumber \t **********/\n");
    printf("Enter number:");
    scanf("%d", &n2);
    printf("%d",UABNumber(n2));

    printf("\n/*********\t reverseNum \t **********/\n");
    printf("Enter number:");
    scanf("%d", &n3);
    printf("%d",reverseNum(n3));

    printf("\n/*********\t smallerThanIndex \t **********/\n");
    printf("Enter Size of the array:");
    scanf("%d", &size);
    //reading the array
    int *numbers = (int *)malloc(size * sizeof(int));
    readArray(numbers, size);
    printf("\n Count for the smaller index values: %d \n", smallerThanIndex(numbers, size));
    free(numbers);

    printf("\n/*********\t arrayDetails \t **********/\n");
    printf("Enter size of the array:");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    readArray(arr, size);
    int *res = arrayDetails(arr, size);
    printf("\nSize of Array   :: %d", size);
    printf("\nMinimum Value   :: %d", res[1]);
    printf("\nMin Value Index :: %d", res[2]);
    printf("\nMean            :: %d", res[3]);
    printf("\nMaximum Value   :: %d", res[4]);
    printf("\nMax Value Index :: %d\n", res[5]);
}