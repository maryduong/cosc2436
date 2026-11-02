#include <iostream>
using namespace std;

#include "radix-sort.h"

int getLength(int number){
    if(number < 0){
        return -1;
    }

    if(number == 0){
        return 1;
    }

    int count = 0; 
    while(number != 0){
        count ++;
        number /= 10;
    }
    return count;
}

int getMaxLength(int a[], int size){
    int maxLength = 0;
    for(int i = 0; i < size; i++){
        int currentLength = getLength(a[i]);
        if(currentLength > maxLength){
            maxLength = currentLength;
        }
    }
    return maxLength; 
}

void radixSort(int a[], int size){
    int* buckets[10]; //array containing pointers (that will point to arrays)
    for(int i = 0; i < 10; i++){
        buckets[i] = new int[size]; //dynamically allocate 10 arrays in buckets array
    }

    int bucketSize[10] = {}; //array to track how many values in different buckets


    int maxLength = getMaxLength (a, size);
    int pow10 = 1; //place value

    for(int digit = 0; digit < maxLength; digit++){
        for(int i = 0; i < size; i++){
            int bucketIndex = abs(a[i]/pow10) % 10;
            buckets[bucketIndex][bucketSize[bucketIndex]] = a[i]; 
            bucketSize[bucketIndex]++; 
        }

        int copyBackIndex = 0; 
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < bucketSize[i]; j++){
                a[copyBackIndex] = buckets[i][j]; //return values back to original array until next place value sort
                copyBackIndex++;
            }
        }

        pow10 *= 10; //go to next place value
    
        for(int i = 0; i < 10; i++){ //reset how many values held in the 10 buckets
            bucketSize[i] = 0; 
        }
    }

    for(int i = 0; i < 10; i++){ //delete dynamically allocated arrays before returning
        delete[] buckets[i];
    }
}