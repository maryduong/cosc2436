#include "node.h"

class List{
    private:
        Node* head;
        Node* tail; 
    public:
        List(): head(nullptr), tail(nullptr){}

        ~List(){
            Node* current;
            while(head != nullptr){
                current = head->next;
                delete head; 
                head = current; 
            }
            tail = nullptr; 
        }

        void append(int value){
            Node* newNode = new Node(value);

            if(head == nullptr){
                head = newNode;
                tail = newNode; 
                return; 
            }

            tail->next = newNode; 
            tail = newNode; 
        }
};

class HashTable{
    private:
        int size;
        List* table;
    public:
        HashTable();
        HashTable(int _size);
        ~HashTable();
        int hashFunction(int key);
        void insert(int key); 
    
};

HashTable::HashTable(){
    size = 10;
    table = new List[size]; 
}

HashTable::HashTable(int _size){
    if(_size <= 0){
        _size = 10;
    }
    size = _size; 
    table = new List[size];
}

HashTable::~HashTable(){
    delete[] table; 
}

int HashTable::hashFunction(int key){
    return ((key % size) + size) % size;
}

void HashTable::insert(int key){
    int index = hashFunction(key); 
    
    table[index].append(key); 
}


