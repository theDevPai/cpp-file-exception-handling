//user input for the number of elements in an array, 
//dynamically allocates memory, and fills the array with user input. 
//Handle any exceptions related to memory allocation.
#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    int numElements;

    // Input the number of elements from the user
    cout << "Enter the number of elements: ";
    cin >> numElements;

    int* arr = nullptr;

    try {
        // Dynamically allocate memory for the array
        arr = new int[numElements];

        // Input array elements from the user
        cout << "Enter " << numElements << " integer elements:" << endl;
        for (int i = 0; i < numElements; ++i) {
            cin >> arr[i];
        }

        // Display the array elements
        cout << "Array elements: ";
        for (int i = 0; i < numElements; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;

        // Deallocate the dynamically allocated memory
        delete[] arr;
        arr = nullptr;
    } catch (const bad_alloc& e) {
        // Handle memory allocation exceptions
        cerr << "Error: Memory allocation failed. " << e.what() << endl;
        delete[] arr; // Make sure to deallocate memory before exiting
    }

    return 0;
}
