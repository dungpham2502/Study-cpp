#include <iostream>
using namespace std;

void towersOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }

    // Step 1: Move (n-1) disks from Source to Auxiliary
    towersOfHanoi(n - 1, source, destination, auxiliary);

    // Step 2: Move the nth (largest) disk from Source to Destination
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;

    // Step 3: Move (n-1) disks from Auxiliary to Destination
    towersOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    towersOfHanoi(n, 'A', 'B', 'C'); 

    return 0;
}
