//user input for age and throws an exception if the age is below 18, 
//indicating it's not suitable for the application.
#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    int age;

    try {
        // Input the age from the user
        cout << "Enter your age: ";
        cin >> age;

        // Check if the age is below 18
        if (age < 18) {
            throw runtime_error("Age is below 18. Not suitable for the application.");
        }

        // If the age is 18 or above, continue with the application logic
        cout << "Welcome to the application!" << endl;
        // Add your application logic here...
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
