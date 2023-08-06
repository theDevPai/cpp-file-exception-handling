//reads a CSV file containing student names and their marks in different subjects. 
//Calculate and display the total marks and average for each student.
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

const int MAX_STUDENTS = 100;
const int MAX_SUBJECTS = 10;

struct Student {
    string name;
    int marks[MAX_SUBJECTS];
    int totalMarks;
    double average;
};

int main() {
    string filename;

    cout << "Enter the filename: ";
    cin >> filename;

    ifstream inputFile(filename);

    if (!inputFile) {
        cerr << "Error opening file '" << filename << "'. Please check if the file exists.\n";
        return 1;
    }

    string line;
    Student students[MAX_STUDENTS];
    int numStudents = 0;

    // Read the header line to get the subject names
    getline(inputFile, line);
    istringstream headerStream(line);
    string subjectName;
    int numSubjects = 0;
    while (getline(headerStream, subjectName, ',')) {
        numSubjects++;
    }

    // Read and process each line of the CSV file
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string name, markStr;
        getline(iss, name, ',');

        Student student;
        student.name = name;
        student.totalMarks = 0;

        // Read marks for each subject and calculate the total marks
        int subjectIndex = 0;
        while (getline(iss, markStr, ',')) {
            int mark = stoi(markStr);
            student.marks[subjectIndex] = mark;
            student.totalMarks += mark;
            subjectIndex++;
        }

        // Calculate the average marks
        student.average = static_cast<double>(student.totalMarks) / numSubjects;

        students[numStudents++] = student;
    }

    inputFile.close();

    // Display the total marks and average for each student
    for (int i = 0; i < numStudents; i++) {
        cout << "Student: " << students[i].name << endl;
        cout << "Total Marks: " << students[i].totalMarks << endl;
        cout << "Average Marks: " << students[i].average << endl;
        cout << endl;
    }

    return 0;
}
