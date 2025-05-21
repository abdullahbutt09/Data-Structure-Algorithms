#include <iostream>
#include <vector>
using namespace std;

// Function to find the successor and predecessor of a given value
void findSuccessorAndPredecessor(const vector<int>& vec, int value) {
    // Search for the index of the value
    int index = -1;
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i] == value) {
            index = i;
            break; // Break once the value is found
        }
    }

    // If the value was not found in the vector
    if (index == -1) {
        cout << "Value not found in the vector!" << endl;
        return;
    }

    // Print the predecessor
    if (index > 0) {
        cout << "Predecessor of " << value << " is: " << vec[index - 1] << endl;
    } else {
        cout << "No predecessor for " << value << endl;
    }

    // Print the successor
    if (index < vec.size() - 1) {
        cout << "Successor of " << value << " is: " << vec[index + 1] << endl;
    } else {
        cout << "No successor for " << value << endl;
    }
}

int main() {
    vector<int> nodesVector = {5, 10, 12, 15, 20, 25}; // Example inorder traversal

    int value = 15;

    // Find Successor and Predecessor
    findSuccessorAndPredecessor(nodesVector, value);

    return 0;
}
