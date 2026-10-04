#pragma once

struct Node{
    int value; 
    Node* next;
};

class LinkedListStack{
    private:
        Node* top;
    public:
        LinkedListStack();
        void push(int value);
        int pop();
};

//----------------------------------

class ArrayStack{
    private:
        int* array; 
        int capacity; 
        int size; 
    public: 
        ArrayStack(); 
        ~ArrayStack();
        void push(int value); 
        int pop(); 

};