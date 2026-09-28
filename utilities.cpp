#include "utilities.h"

void print(int a[], int size){
    cout << a[0];
    for (int i = 1; i < size; i++){
        cout << " " << a[i];
    }
    cout << endl; 
}

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}