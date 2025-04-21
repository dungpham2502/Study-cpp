#include <iostream>

struct DNode {
    int data;
    DNode *prev;
    DNode *next;

    DNode(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList
{
    DNode *head;
    DNode *tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtTail(int val) {
        DNode *newNode = new DNode(val);
        if (tail != nullptr) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void deleteFromTail(int val) {
        if (tail != nullptr) {
            return;
        }
        DNode *temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        }
        else 
        {
            head = nullptr;
        }
        delete temp;
    }

    void insertAtHead(int val) 
    {
        DNode *newNode = new DNode(val);
        if (head == nullptr) 
        {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtTail(int val)
    {
        DNode *newNode = new DNode(val);
        if (head == nullptr)
        {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
};
