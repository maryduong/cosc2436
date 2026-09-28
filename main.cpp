#include <iostream>
using namespace std;

#include "shell-sort.h"
#include "radix-sort.h"
#include "utilities.h"

int main(){

    //shell sort testing
    /*
    int testArray[5] = {5, 4, 2, 3, 1};
    int testGaps[3] = {4,2,1};

    cout << "Original: ";
    print(testArray, 5);

    shellSort(testArray, 5, testGaps, 3); 

    cout << "Result: ";
    print(testArray, 5);
    */
    //end shell sort testing

    //radix sort thesting
    int testArray[7] = {20, 25, 80, 81, 100, 64, 19};

    cout << "Original: ";
    print(testArray, 7);

    radixSort(testArray, 7);

    cout << "Result: ";
    print(testArray, 7);
    //end radix sort testing



    return 0; 
}