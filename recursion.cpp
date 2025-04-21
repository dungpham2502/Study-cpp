#include <iostream>

int findMax(int arr[], int n)
{
    if (n == 1)
    {
        return arr[0];
    }
    return std::max(arr[n - 1], findMax(arr, n - 1));
}

int main()
{
    int arr[] = {3, 1, 4, 5, 7, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Maximum element is: " << findMax(arr, size) << std::endl;
    return 0;
}