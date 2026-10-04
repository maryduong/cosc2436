// linked list based stack

#include "stack.h"

LinkedListStack::LinkedListStack(){
    top = nullptr; 
}

void LinkedListStack::push(int value){
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = top;
    top = newNode;
}

int LinkedListStack::pop(){
    if(top != nullptr){
        Node* temp = top; 
        int poppedVal = top->value;
        top = top->next;
        delete temp;
        return poppedVal;
    }
    return -1; 
}

// array based stack (size & capacity)---------------------------------------
// unbounded

ArrayStack::ArrayStack(){
    capacity = 2; 
    array = new int[capacity]; 
    size = 0;
}

ArrayStack::~ArrayStack(){
    delete[] array;
}

void ArrayStack::push(int value){
    if(size == capacity){
        capacity *= 2; 
        int* newArray = new int[capacity]; 
        for(int i = 0; i < size; i++){
            newArray[i] = array[i]; 
        }
        delete[] array; 
        array = newArray; 
    }
    array[size] = value; 
    size++;
}

int ArrayStack::pop(){
    if(size == 0){
        return -1; 
    }
    int temp = array[size-1];
    size--;
    return temp; 
}