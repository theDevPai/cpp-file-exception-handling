//reads two float values from the user and performs division, 
//handling the Floating-Point Exception.
#include <iostream>
#include <cfenv>
#include <cmath>
#include <cerrno>
#include <cstring>
using namespace std;

int main() {
    float num1, num2;

    // Input the two numbers from the user
    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    // Set the floating-point environment to trap divide-by-zero
    feclearexcept(FE_ALL_EXCEPT);

    try {
        // Perform the division
        float result = num1 / num2;

        // Check for divide-by-zero exception
        if (fetestexcept(FE_DIVBYZERO)) {
            throw runtime_error("Division by zero is not allowed.");
        }

        // Display the result
        cout << "Result: " << result << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
