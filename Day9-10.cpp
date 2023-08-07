//eads a string from the user and converts it to an integer using stoi(). 
//Handle any exceptions that may occur due to invalid input.
#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    string inputString;
    int integerValue = 0;

    cout << "Enter a string to convert to an integer: ";
    cin >> inputString;

    try {
        integerValue = stoi(inputString);
        cout << "Converted integer value: " << integerValue << endl;
    } catch (const invalid_argument& e) {
        cerr << "Error: Invalid input string. " << e.what() << endl;
    } catch (const out_of_range& e) {
        cerr << "Error: Value out of range. " << e.what() << endl;
    }

    return 0;
}
