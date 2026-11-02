#include <iostream>
using namespace std;

#include "shell-sort.h"

//sort an interleaved array created from original array using a gap value 
void interleaved(int a[], int size, int gap){
    for (int i = 0; i < gap; i++){
        for(int j = i + gap; j < size; j += gap){
            while(j - gap >= 0 && a[j] < a[j - gap]){
                int temp = a[j - gap];
                a[j - gap] = a[j];
                a[j] = temp;
                //print(a, size); 
                j = j - gap; 
            }
        }
    }
}

//array of gap values creates interleaved arrays to sort orignal array
void shellSort(int a[], int size, int gaps[], int nGaps){
    for(int i = 0; i < nGaps; i++){
        int gap = gaps[i]; 
        interleaved(a, size, gap);
    }
}