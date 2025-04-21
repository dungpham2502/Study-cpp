#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    };
};

class SinglyLinkedList {
    Node *head;
public:
    SinglyLinkedList() {
        head = nullptr;
    }
    
    void insertAtEnd(int val) {
        Node *newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void deleteAtEnd() {
        if (head == nullptr)
            return;
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node *temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void display() {
        Node *temp = head;
        std::cout << "Linked List: ";
        while (temp != nullptr)
        {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }

    int countRecursive(Node *temp)
    {
        if (temp == nullptr) {
            return 0;
        }
        return (1 + countRecursive(temp->next));
    };

    int count()
    {
        return countRecursive(head);
    }

    void reverse()
    {
        Node *prev = nullptr;
        Node *curr = head;
        Node *next = nullptr;
        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = curr->next;
        }
        head = prev;
    }

    ~SinglyLinkedList() {
        while(head != nullptr) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    SinglyLinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.display();

    std::cout << "Number of nodes: " << list.count() << std::endl;

    return 0;
}
