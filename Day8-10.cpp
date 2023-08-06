//reads a text file, removes all punctuation marks, 
//converts all text to lowercase, and saves the modified content to a new file.
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

bool isPunctuation(char c) {
    return ispunct(static_cast<unsigned char>(c));
}

int main() {
    string filename, outputFilename;

    cout << "Enter the input filename: ";
    cin >> filename;

    cout << "Enter the output filename: ";
    cin >> outputFilename;

    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error opening input file '" << filename << "'. Please check if the file exists.\n";
        return 1;
    }

    ofstream outputFile(outputFilename);
    if (!outputFile) {
        cerr << "Error opening output file '" << outputFilename << "'.\n";
        return 1;
    }

    char c;
    while (inputFile.get(c)) {
        if (!isPunctuation(c)) {
            c = tolower(c);
            outputFile << c;
        }
    }

    cout << "Text processing complete. Modified content saved to '" << outputFilename << "'.\n";

    inputFile.close();
    outputFile.close();

    return 0;
}
