//performs a risky operation 
//(e.g., accessing an out-of-bounds array element) and 
//catches and handles the appropriate exception.
#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    try {
        int arr[] = {1, 2, 3, 4, 5};
        int index;

        cout << "Enter the index to access the array element: ";
        cin >> index;

        if (index >= 0 && index < sizeof(arr) / sizeof(arr[0])) {
            int element = arr[index];
            cout << "Element at index " << index << " is: " << element << endl;
        } else {
            throw out_of_range("Invalid index. Array element is out of bounds.");
        }
    } catch (const out_of_range& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
