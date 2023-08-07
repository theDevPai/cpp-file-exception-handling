//reads a file containing numeric data and calculates the sum. 
//Handle any exceptions that may occur during file reading.
#include <iostream>
#include <fstream>
#include <numeric>
#include <stdexcept>
using namespace std;

int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    ifstream inputFile;
    inputFile.exceptions(ifstream::failbit | ifstream::badbit);

    try {
        inputFile.open(filename);

        double sum = 0.0;
        double num;

        while (inputFile >> num) {
            sum += num;
        }

        if (inputFile.eof()) {
            cout << "Sum of the numbers: " << sum << endl;
        } else {
            cerr << "Error: File contains invalid data or could not be read completely." << endl;
        }

        inputFile.close();
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
