//read data from a file and display its contents on the console.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    //create a text file
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    ifstream inputFile(filename);

    if (!inputFile) {
        cerr << "Error opening file '" << filename << "'. Please check if the file exists.\n";
        return 1;
    }

    cout << "Contents of the file '" << filename << "':\n";

    string line;
    while (getline(inputFile, line)) {
        cout << line << endl;
    }

    inputFile.close();

    return 0;
}
