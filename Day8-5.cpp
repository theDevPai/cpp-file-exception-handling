//reads a list of integers from a file, sorts them, and writes the sorted list back to the file.
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
    string filename;

    cout << "Enter the filename: ";
    cin >> filename;

    ifstream inputFile(filename);

    if (!inputFile) {
        cerr << "Error opening file '" << filename << "'. Please check if the file exists.\n";
        return 1;
    }

    const int MAX_SIZE = 1000; // Assuming a maximum of 1000 integers in the file
    int numbers[MAX_SIZE];
    int num;
    int count = 0;

    while (inputFile >> num) {
        if (count >= MAX_SIZE) {
            cerr << "The number of integers in the file exceeds the maximum allowed limit.\n";
            return 1;
        }
        numbers[count++] = num;
    }

    inputFile.close();

    sort(numbers, numbers + count);

    ofstream outputFile(filename);

    if (!outputFile) {
        cerr << "Error opening file '" << filename << "' for writing.\n";
        return 1;
    }

    for (int i = 0; i < count; i++) {
        outputFile << numbers[i] << " ";
    }

    outputFile.close();

    cout << "Sorted list has been written back to the file '" << filename << "'.\n";

    return 0;
}
