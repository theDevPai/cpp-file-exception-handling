//reads a file containing student data and converts the GPA to a letter grade (e.g., A, B, C, etc.). 
//Handle any exceptions that may occur during the conversion.
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
using namespace std;

char getLetterGrade(double gpa) {
    if (gpa >= 4.0) return 'A';
    if (gpa >= 3.0) return 'B';
    if (gpa >= 2.0) return 'C';
    if (gpa >= 1.0) return 'D';
    return 'F';
}

int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    ifstream inputFile;
    inputFile.exceptions(ifstream::failbit | ifstream::badbit);

    try {
        inputFile.open(filename);

        string name;
        double gpa;

        while (inputFile >> name >> gpa) {
            if (gpa < 0.0 || gpa > 4.0) {
                throw runtime_error("Invalid GPA value encountered.");
            }

            char letterGrade = getLetterGrade(gpa);
            cout << "Student: " << name << ", GPA: " << gpa << ", Letter Grade: " << letterGrade << endl;
        }

        inputFile.close();
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
