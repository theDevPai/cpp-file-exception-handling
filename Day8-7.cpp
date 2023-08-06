//encrypts the contents of a file using a 
//simple substitution cipher and saves the encrypted data to a new file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to perform the substitution cipher encryption
string encrypt(const string& message, int shift) {
    string encryptedMessage = message;

    for (char& c : encryptedMessage) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = (c - base + shift) % 26 + base;
        }
    }

    return encryptedMessage;
}

int main() {
    string inputFile, outputFile;
    int shift;

    cout << "Enter the input filename: ";
    cin >> inputFile;

    cout << "Enter the output filename: ";
    cin >> outputFile;

    cout << "Enter the shift value for the cipher: ";
    cin >> shift;

    ifstream input(inputFile);
    if (!input) {
        cerr << "Error opening input file '" << inputFile << "'. Please check if the file exists.\n";
        return 1;
    }

    ofstream output(outputFile);
    if (!output) {
        cerr << "Error opening output file '" << outputFile << "'.\n";
        return 1;
    }

    string line;
    while (getline(input, line)) {
        string encryptedLine = encrypt(line, shift);
        output << encryptedLine << endl;
    }

    cout << "Encryption complete. Encrypted data saved to '" << outputFile << "'.\n";

    input.close();
    output.close();

    return 0;
}
