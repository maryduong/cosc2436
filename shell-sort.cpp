#include <iostream>
using namespace std;

void print(int a[], int size);
void interleaved(int a[], int size, int gap);
void shellSort(int a[], int size, int gaps[], int nGaps);

int main(){
    
    //shell sort testing
    int testArray[5] = {5, 4, 2, 3, 1};
    int testGaps[3] = {4,2,1};

    cout << "Original: ";
    print(testArray, 5);

    shellSort(testArray, 5, testGaps, 3); 

    cout << "Result: ";
    print(testArray, 5);

    return 0; 
}

void print(int a[], int size){
    cout << a[0];
    for (int i = 1; i < size; i++){
        cout << " " << a[i];
    }
    cout << endl; 
}

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
        print(a,size); 
    }
}