//reads a text file and replaces all occurrences of a 
//specific word with another word, then saves the modified content to a new file.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void replaceWord(string& line, const string& oldWord, const string& newWord) {
    size_t pos = 0;
    while ((pos = line.find(oldWord, pos)) != string::npos) {
        line.replace(pos, oldWord.length(), newWord);
        pos += newWord.length();
    }
}

int main() {
    string filename, outputFilename;
    string oldWord, newWord;

    cout << "Enter the input filename: ";
    cin >> filename;

    cout << "Enter the output filename: ";
    cin >> outputFilename;

    cout << "Enter the word to replace: ";
    cin >> oldWord;

    cout << "Enter the new word: ";
    cin >> newWord;

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

    string line;
    while (getline(inputFile, line)) {
        replaceWord(line, oldWord, newWord);
        outputFile << line << endl;
    }

    cout << "Word replacement complete. Modified content saved to '" << outputFilename << "'.\n";

    inputFile.close();
    outputFile.close();

    return 0;
}
