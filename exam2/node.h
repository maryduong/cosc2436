#pragma once

struct Node{
    int value; 
    Node* next = nullptr;
    Node(int value): value(value), next(nullptr){};
};
