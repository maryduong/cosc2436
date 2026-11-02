#include "utilities.h"

void maxHeapDown(int parentIndex, int array[], int size){
    int childIndex = parentIndex * 2 + 1; //first child (left side)

    while(childIndex < size){ //if possible children exist
        int parentValue = array[parentIndex];
        int maxValue = parentValue; 
        int maxIndex = -1; 

        for(int i = 0; i < 2 && childIndex + i < size; i++){
            if(array[childIndex + i] > maxValue){
                maxValue = array[childIndex + i];
                maxIndex = childIndex + i;
            }
        }

        if(maxValue == parentValue){
            return; //parent is max value- no swap needed
        }
        
        else{
            swap(array, parentIndex, maxIndex);
            parentIndex = maxIndex;
            childIndex = parentIndex * 2 + 1; 
        }
    }
}

void heapSort(int array[], int size){
    for(int i = size / 2 - 1; i >= 0; i--){
        maxHeapDown(i, array, size); //turn array into max heap
    }

    for(int i = size - 1; i > 0; i--){ //for each loop, size decrements by 1 
        swap(array, 0, i); //move max element to the end- it is now sorted
        maxHeapDown(0, array, i); //heapify (max heap) the unsorted side
    }
}

//------------------------------------------------------------

void maxHeapUp(int newNodeIndex, int array[]){ //restores max heap when new node is inserted
    while(newNodeIndex > 0){
        int parentIndex = (newNodeIndex - 1) / 2; //find the parent of the new node
        if(array[newNodeIndex] <= array[parentIndex]){
            return; 
        }
        else{
            swap(array, parentIndex, newNodeIndex); //since the new node value is bigger than parent value, swap
            newNodeIndex = parentIndex;
        }
    }
}