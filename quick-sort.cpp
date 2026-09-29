#include "utilities.h"

int partition(int arr[], int low, int high){
    int mid = low + ((high - low) / 2); 
    int pivot = arr[mid]; //pivot is middle element

    bool done = false;
    while(!done){
        while(pivot > arr[low]){
            low++; //low index is incremented until a value greater than pivot found
        }
        while(pivot < arr[high]){
            high--; //high index is decremented until a value less than or equal to pivot found
        }

        if(low >= high){ //if  0 or 1 elements left, then all elements are partitioned
            done = true; 
        }
        else{
            swap(arr, low, high); 
            low++; 
            high--; 
        }
    }
    return high; 
}

void quickSort(int arr[], int low, int high){ 
    if(low >= high){
        return;
    }

    int pivot = partition(arr, low, high);

    quickSort(arr, low, pivot); //recursively sort left side 
    quickSort(arr, pivot + 1, high); //right side
}

int quickSelect(int arr[], int low, int high, int k){ //only partially sorts array; returns kth smallest element in array; ex: k = 0 returns smallest element, k = 1 returns second smallest element
    if(low >= high){
        return arr[low]; //return if 0 or 1 elements to sort
    }

    int lastLow = partition(arr, low, high); 

    if(k <= lastLow){
        return quickSelect(arr, low, lastLow, k); //if k less than index of lastLow, recur left side
    }

    return quickSelect(arr, lastLow + 1, high, k); //else recur right side
}

void anotherQuickSort(int* array, int low, int high){
    if(low >= high){ //return if nothing to sort
        return;
    }

    int pivotIndex = high; //pivot is right most element

    //use pivot element to partition elements: less than | pivot | greater than
    int tempIndex = pivotIndex - 1;

    while(array[pivotIndex] <  array[tempIndex]){
        tempIndex--; 
    }
    tempIndex++;

    int tempVal = array[tempIndex];
    array[tempIndex] = array[pivotIndex];
    array[pivotIndex] = tempVal; 
    pivotIndex = tempIndex; 
    //

    anotherQuickSort(array, low, pivotIndex-1); //sort left
    anotherQuickSort(array, pivotIndex+1, high); //sort right
}
