#include <iostream>
#include <queue>

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
            return;
        }
        while(q1.size() > 1)
        {
            int num = q1.front();
            q2.push(num);
            q1.pop();
        }
        int lastNum = q1.front();
        q1.pop();
        while(q2.size() > 0)
        {
            int num = q2.front();
            q1.push(num);
            q2.pop();
        }
        return lastNum;
    }

    int top()
    {
        if (q1.empty())
        {
            std::cout << "Stack is empty";
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
        std::cout << "Queue: ";
        std::queue<int> temp = q1;
        while(!temp.empty())
        {
            std::cout << temp.front() << " ";
            temp.pop();
        }
        std::cout << "\n";
    }
};

int main() {
    StackUsingQueues stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    std::cout << "Stack top: " << stack.top() << "\n"; // 30
    stack.pop();
    
    std::cout << "Stack top after pop: " << stack.top() << "\n"; // 20
    stack.display(); // 10 20

    return 0;
}