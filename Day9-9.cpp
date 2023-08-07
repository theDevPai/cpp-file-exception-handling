//user input for two integer values and calculates their 
//quotient using only bitwise operators. 
//Handle any exceptions arising from incorrect input.
#include <iostream>
#include <stdexcept>
using namespace std;

int bitwiseDivision(int dividend, int divisor) {
    if (divisor == 0) {
        throw runtime_error("Division by zero is not allowed.");
    }

    int quotient = 0;
    int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;

    unsigned int uDividend = abs(dividend);
    unsigned int uDivisor = abs(divisor);

    while (uDividend >= uDivisor) {
        int power = 0;
        while ((uDivisor << power) <= uDividend) {
            power++;
        }
        power--;
        uDividend -= uDivisor << power;
        quotient += 1 << power;
    }

    return sign * quotient;
}

int main() {
    int num1, num2;

    try {
        cout << "Enter the first number: ";
        cin >> num1;

        cout << "Enter the second number: ";
        cin >> num2;

        int result = bitwiseDivision(num1, num2);
        cout << "Quotient: " << result << endl;

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
