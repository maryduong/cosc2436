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
