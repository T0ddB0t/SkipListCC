#include <iostream>
#include <cstdlib>
#include <ctime>
#include "SkipList.h"

// Your Skip List code here...

int main() {
    srand(time(0));  // Seed for random number generation
    
    SkipList<int> skipList;

    // Insert some elements
    skipList.skipListInsert(10);
    skipList.skipListInsert(20);
    skipList.skipListInsert(15);

    // Search for an element
    int key = 20;
    int* result = skipList.skipListSearch(key);
    if (result != nullptr) {
        cout << "Found key " << key << " in the Skip List." << endl;
    } else {
        cout << "Key " << key << " not found in the Skip List." << endl;
    }
    
    return 0;
}