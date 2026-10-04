#pragma once

#include "node.h"

class LinkedListQueue{
    private:
        Node* head; 
        Node* tail; 
    public:
        LinkedListQueue(){head = nullptr; tail = nullptr;};
        void enqueue(int value);
        int dequeue();
};

class ArrayQueue{
    private:
        int* array; 
        int size;
        int capacity;
        int frontIndex; 
    public:
        ArrayQueue(){
            size = 0; 
            capacity = 2; 
            frontIndex = 0; 
            array = new int[capacity];
        }
        ~ArrayQueue(){
            delete[] array;
        }
        ArrayQueue& operator=(const ArrayQueue& other); 
        void enqueue(int value);
        int dequeue(); 
        void resizeArray(); 
}; 

ArrayQueue& ArrayQueue::operator=(const ArrayQueue& other){
    if(this == &other){ //check for self copy
        return *this; 
    }

    size = other.size; //copy non dynamic
    capacity = other.capacity; 
    frontIndex = other.frontIndex; 

    int* newArray = new int[capacity]; //deep copy

    for(int i = 0; i < size; i++){
        int index = (frontIndex + i) % capacity;
        newArray[i] = other.array[index];
    }
    frontIndex = 0;
    delete[] array; 
    array = newArray; 

    return *this; 
}

