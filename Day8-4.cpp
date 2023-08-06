//count the number of lines, words, and characters in a given text file.
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
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

    int lineCount = 0;
    int wordCount = 0;
    int charCount = 0;

    string line;
    while (getline(inputFile, line)) {
        lineCount++;
        charCount += line.length();

        istringstream iss(line);
        string word;
        while (iss >> word) {
            wordCount++;
        }
    }

    inputFile.close();

    cout << "Number of lines: " << lineCount << endl;
    cout << "Number of words: " << wordCount << endl;
    cout << "Number of characters: " << charCount << endl;

    return 0;
}
