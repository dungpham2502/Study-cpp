#include <iostream>
#include <queue>
#include <stack>

class StackUsingQueues 
{
    std::queue<int> q1, q2;

public:
    // push
    void push(int x) 
    {
        q1.push(x);
    }

    // pop
    int pop()
    {
        if (q1.empty()) {
            std::cout << "Stack is empty!\n";
            return -1;
        }
        while(q1.size() > 1)
        {
            int num = q1.front();
            q2.push(num);
            q1.pop();
        }
        int lastNum = q1.front();
        q1.pop();
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        return lastNum;
    }

    int top()
    {
        if (q1.empty())
        {
            std::cout << "Stack is empty\n";
            return -1;
        }

        while (q1.size() > 1) 
        {
            q2.push(q1.front());
            q1.pop();
        }

        int topElement = q1.front();
        q2.push(topElement);
        q1.pop();
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        return topElement;
    }

    void display()
    {
        std::cout << "Queue (as Stack): ";
        std::queue<int> temp = q1;
        while(!temp.empty())
        {
            std::cout << temp.front() << " ";
            temp.pop();
        }
        std::cout << "\n";
    }
};

// Function to remove all elements from a stack recursively
void RecursiveRemove(std::stack<int>& stack) {
    if (stack.empty()) return; // Base case: Stop when stack is empty
    stack.pop(); // Remove top

    RecursiveRemove(stack); // Recursive call
}

int main() {
    StackUsingQueues stack;
    std::stack<int> stack2;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Stack top: " << stack.top() << "\n"; // 30
    stack.pop();
    
    std::cout << "Stack top after pop: " << stack.top() << "\n"; // 20
    stack.display(); // Expected: 10 20

    // Recursive Stack Removal
    stack2.push(12);
    stack2.push(22);
    stack2.push(32);

    std::cout << "Stack 2 before recursive remove:\n";
    std::stack<int> tempStack = stack2; // Copy to print elements
    while (!tempStack.empty()) {
        std::cout << tempStack.top() << " ";
        tempStack.pop();
    }
    std::cout << "\n";

    RecursiveRemove(stack2);

    std::cout << "Stack 2 after recursive remove: ";
    if (stack2.empty()) std::cout << "Stack is empty\n";
    else std::cout << "Stack is NOT empty\n";

    return 0;
}
