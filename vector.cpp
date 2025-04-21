/*
In c++ a sequence is any container that maintains order of elements
Standard template lib containers such as std::vector, std::list, std::deque


Vectors
std::vector is a dynamic array that can grow and shrink as needed
- dynamic array (e.g. push_back)
- random access
- contiguous memory
*/
#include <iostream>
#include <vector>
#include <list>

bool containsHelper(const std::vector<int>& S, int k, int index)
{
    if (index >= S.size())
        return false;
    if (S[index] == k)
        return true;
    return containsHelper(S, k, index + 1);
}

bool contains(const std::vector<int> &S, int k)
{
    return containsHelper(S, k, 0);
}

    int main()
{
    std::vector<int> numbers;
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    numbers.push_back(40);


    std::cout << numbers[0] << "\n";
    std::cout << numbers.front() << "\n";
    std::cout << numbers.back() << "\n";
    std::cout << numbers.at(1) << "\n";

    std::vector<int>::iterator it;
    for (it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << "\n";
    }

    std::cout << (contains(numbers, 10) ? "Found 5 in sequence." : "5 not found in sequence.") << std::endl;
    std::cout << (contains(numbers, 2) ? "Found 2 in sequence." : "2 not found in sequence.") << std::endl;
}
