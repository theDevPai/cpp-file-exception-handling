//copy the contents of one file to another.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string sourceFilename, destinationFilename;

    cout << "Enter the source filename: ";
    cin >> sourceFilename;

    cout << "Enter the destination filename: ";
    cin >> destinationFilename;

    ifstream sourceFile(sourceFilename);
    if (!sourceFile) {
        cerr << "Error opening source file '" << sourceFilename << "'. Please check if the file exists.\n";
        return 1;
    }

    ofstream destinationFile(destinationFilename);
    if (!destinationFile) {
        cerr << "Error opening destination file '" << destinationFilename << "'.\n";
        return 1;
    }

    char ch;
    while (sourceFile.get(ch)) {
        destinationFile.put(ch);
    }

    sourceFile.close();
    destinationFile.close();

    cout << "File copied successfully from '" << sourceFilename << "' to '" << destinationFilename << "'.\n";

    return 0;
}
