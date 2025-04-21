#include <iostream>

struct CNode {
    int data;
    CNode* next;

    CNode(int val) {  // Constructor
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
    CNode* tail; // Tail pointer to keep track of last node

public:
    CircularLinkedList() {  // Constructor
        tail = nullptr;
    }

    // Insert at the end
    void insertAtEnd(int val) {
        CNode* newNode = new CNode(val);
        if (tail == nullptr) { // If list is empty
            tail = newNode;
            tail->next = tail; // Circular link
            return;
        }
        CNode* head = tail->next;
        newNode->next = head; // New node points to head
        tail->next = newNode; // Tail's next points to new node
        tail = newNode; // Update tail to new node
    }

    // Insert at the front
    void insertAtHead(int val) {
        CNode* newNode = new CNode(val);
        if (tail == nullptr) { // If list is empty
            tail = newNode;
            tail->next = tail;
            return;
        }
        newNode->next = tail->next; // New node points to head
        tail->next = newNode; // Tail still points to new head
    }

    // Delete from head
    void deleteFromHead() {
        if (tail == nullptr) return; // Empty list
        if (tail->next == tail) { // Only one node in the list
            delete tail;
            tail = nullptr;
            return;
        }
        CNode* temp = tail->next; // Get head
        tail->next = temp->next; // Tail now points to the next node
        delete temp; // Delete old head
    }

    // Delete from the end
    void deleteFromTail() {
        if (tail == nullptr) return; // Empty list
        if (tail->next == tail) { // Only one node
            delete tail;
            tail = nullptr;
            return;
        }
        CNode* temp = tail->next; // Start from head
        while (temp->next != tail) { // Traverse until second-last node
            temp = temp->next;
        }
        temp->next = tail->next; // Link last node to head
        delete tail; // Delete old tail
        tail = temp; // Update new tail
    }

    // Display the list
    void display() {
        if (tail == nullptr) {
            std::cout << "List is empty\n";
            return;
        }
        CNode* temp = tail->next; // Start from head
        do {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != tail->next); // Loop until back to head
        std::cout << "(back to head)\n";
    }

    // Destructor to free memory
    ~CircularLinkedList() {
        if (tail == nullptr) return;
        CNode* temp = tail->next;
        while (temp != tail) { // Delete nodes one by one
            CNode* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        delete tail; // Delete last node
        tail = nullptr;
    }
};

int main() {
    CircularLinkedList list;

    // Insertions
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtHead(5);
    list.display(); // Expected: 5 -> 10 -> 20 -> 30 -> (back to head)

    // Deletions
    list.deleteFromHead();
    list.display(); // Expected: 10 -> 20 -> 30 -> (back to head)

    list.deleteFromTail();
    list.display(); // Expected: 10 -> 20 -> (back to head)

    return 0;
}
