//reads a text file and attempts to 
//convert its contents to an integer. 
//Handle any exceptions that may arise from invalid input.
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
using namespace std;

int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    ifstream inputFile;
    inputFile.exceptions(ifstream::failbit | ifstream::badbit);

    try {
        inputFile.open(filename);

        int sum = 0;
        string line;

        while (getline(inputFile, line)) {
            try {
                // Attempt to convert the line to an integer
                int num = stoi(line);
                sum += num;
            } catch (const invalid_argument& e) {
                cerr << "Error: Invalid input in the file: " << line << endl;
            } catch (const out_of_range& e) {
                cerr << "Error: Value out of range in the file: " << line << endl;
            }
        }

        cout << "Sum of the integers in the file: " << sum << endl;

        inputFile.close();
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
