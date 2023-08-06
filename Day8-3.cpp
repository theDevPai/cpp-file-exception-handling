//input from the user and saves it to a file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string filename;

    cout << "Enter the filename to save the input: ";
    cin >> filename;

    ofstream outputFile(filename);

    if (!outputFile) {
        cerr << "Error opening file '" << filename << "'. Unable to save input.\n";
        return 1;
    }

    cout << "Enter your input (type 'exit' on a new line to stop):\n";

    string line;
    while (true) {
        getline(cin, line);
        if (line == "exit")
            break;
        outputFile << line << endl;
    }

    outputFile.close();

    cout << "Input has been saved to the file '" << filename << "'.\n";

    return 0;
}
