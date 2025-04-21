#include <iostream>
#include <cstring> // for memset
using namespace std;

// The key of an entry has to be nonzero
struct entry {
    size_t key;
    char* value;
};

// Hash function: returns index using modulo
size_t hashFunction(int x, size_t N) {
    return x % N;
}

// Insert an entry into the table using linear probing
void put(struct entry e, struct entry* table, size_t N) {
    size_t position = hashFunction(e.key, N);

    if (table[position].key == 0) {
        table[position] = e;
    } else {
        size_t firstPosition = position;

        do {
            position = (position + 1) % N;

            if (table[position].key == 0) {
                table[position] = e;
                return;
            }
        } while (position != firstPosition);

        printf("Could not put for (%s, %zu)\n", e.value, e.key);
    }
}

int main() {
    struct entry TABLE[15];

    // Set all TABLE slots to (0, NULL)
    memset(TABLE, 0, sizeof(struct entry) * 15);

    struct entry listOfEntries[10] = {
        {14, (char*)"Liam"},
        {3, (char*)"Emma"},
        {1, (char*)"Olivia"},
        {18, (char*)"Noah"},
        {9, (char*)"William"},
        {17, (char*)"James"},
        {20, (char*)"Ava"},
        {15, (char*)"Logan"},
        {7, (char*)"Isabella"},
        {47, (char*)"Megan"}
    };

    for (int i = 0; i < 10; i++) {
        put(listOfEntries[i], TABLE, 15);
    }

    // Optional: print final table contents
    cout << "\nFinal Hash Table:\n";
    for (int i = 0; i < 15; i++) {
        if (TABLE[i].key != 0)
            cout << "Index " << i << ": (" << TABLE[i].key << ", " << TABLE[i].value << ")\n";
        else
            cout << "Index " << i << ": EMPTY\n";
    }

    return 0;
}
