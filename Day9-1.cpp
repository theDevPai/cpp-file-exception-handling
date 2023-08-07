//takes two integer inputs from the user and performs division, 
//handling the Divide By Zero exception.
#include <iostream>
using namespace std;

int main() {
    int num1, num2;

    // Input the two numbers from the user
    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    try {
        if (num2 == 0) {
            throw runtime_error("Division by zero is not allowed.");
        }

        // Perform the division and display the result
        double result = static_cast<double>(num1) / num2;
        cout << "Result: " << result << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
