#include "queues.h"

// linked list based queue 

void LinkedListQueue::enqueue(int value){
    Node* newNode = new Node;
    newNode->value = value; 
    
    if(head == nullptr){
        head = newNode; 
        tail = newNode; 
    }
    else{
        tail->next = newNode; 
        tail = newNode;
    }
}

int LinkedListQueue::dequeue(){
    if(head == nullptr){
        return -1; 
    }

    if(head->next == nullptr){
        tail = nullptr; 
    }

    Node* temp = head; 
    int tempValue = head->value; 
    head = head->next;
    delete temp; 
    
    return tempValue;
}

// array based queue

void ArrayQueue::resizeArray(){
    int newCapacity = capacity * 2; 
    int* newArray = new int[newCapacity];

    for(int i = 0; i < size; i++){
        int index = (frontIndex + i) % capacity;
        newArray[i] = array[index]; 
    }

    capacity = newCapacity; 
    frontIndex = 0;

    delete[] array;
    array = newArray; 
}

void ArrayQueue::enqueue(int value){
    if(size == capacity){
        resizeArray();
    }

    int enqueueIndex = (frontIndex + size) % capacity; 
    array[enqueueIndex] = value; 
    size++; 
}

int ArrayQueue::dequeue(){
    if(size == 0){
        return -1; 
    }

    int temp = array[frontIndex];
    size--;
    frontIndex = (frontIndex + 1) % capacity; 

    return temp;
}
