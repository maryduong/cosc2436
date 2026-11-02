void merge(int arr[], int low, int mid, int high){
    int mergedSize = high - low + 1;
    int* mergedNumbers = new int[mergedSize]; //space complexity O(n)

    int leftPos = low; 
    int rightPos = mid + 1; 
    int mergePos = 0;

    while(leftPos <= mid && rightPos <= high){ //while left AND right partitions not empty, add the smaller elements to new array first
        if(arr[leftPos] <= arr[rightPos]){
            mergedNumbers[mergePos] = arr[leftPos];
            leftPos++;
        }
        else{
            mergedNumbers[mergePos] = arr[rightPos];
            rightPos++;
        }
        mergePos++;
    }

    while(leftPos <= mid){ //while left partition not empty, add to new array
        mergedNumbers[mergePos] = arr[leftPos];
        leftPos++;
        mergePos++;
    }

    while(rightPos <= high){ //while right partition not empty, add to new array
        mergedNumbers[mergePos] = arr[rightPos];
        rightPos++;
        mergePos++;
    }

    for(int i = 0; i < mergedSize; i++){ 
        arr[low + i] = mergedNumbers[i];
    }

    delete[] mergedNumbers;
}

void mergeSort(int arr[], int low, int high){
    if(low >= high){ //nothing to sort
        return; 
    }

    int mid = low + ((high - low) / 2);

    mergeSort(arr, low, mid); //splits array in halves until splits only have 1 element
    mergeSort(arr, mid + 1, high);

    merge(arr, low, mid, high); //merge split arrays in ascending element order
}