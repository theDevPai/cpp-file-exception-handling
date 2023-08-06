//read a binary file containing an array of integers and find the sum of all elements.
#include <iostream>
#include <fstream>
using namespace std;


int main() {
    string filename;

    cout << "Enter the filename: ";
    cin >> filename;

    ifstream inputFile(filename, ios::binary);

    if (!inputFile) {
        cerr << "Error opening file '" << filename << "'. Please check if the file exists.\n";
        return 1;
    }

    // Get the length of the file
    inputFile.seekg(0, ios::end);
    int fileSize = inputFile.tellg();
    inputFile.seekg(0, ios::beg);

    // Calculate the number of integers in the file
    int numIntegers = fileSize / sizeof(int);

    // Read the integers from the binary file into an array
    int* numbers = new int[numIntegers];
    inputFile.read(reinterpret_cast<char*>(numbers), fileSize);
    inputFile.close();

    // Calculate the sum of all elements
    int sum = 0;
    for (int i = 0; i < numIntegers; i++) {
        sum += numbers[i];

    }

    delete[] numbers;

    cout << "Sum of all elements in the binary file: " << sum << endl;

    return 0;
}
