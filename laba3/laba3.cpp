#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
    string lastName;
    string firstName;
    int mathGrade;
    int physicsGrade;
    int computerGrade;
};

int main() {
    // зчитуємо назву предмету з клавіатури
    string subject;
    cout << "Enter the name of the subject: ";
    cin >> subject;
    
    // відкриваємо файл для зчитування даних
    ifstream inputFile("data.txt");
    if (!inputFile) {
        cerr << "Error: could not open data file" << endl;
        return 1;
    }
    
    // зчитуємо дані з файлу та зберігаємо їх у масиві студентів
    const int numStudents = 10;
    Student students[numStudents];
    for (int i = 0; i < numStudents; i++) {
        inputFile >> students[i].lastName >> students[i].firstName
                  >> students[i].mathGrade >> students[i].physicsGrade
                  >> students[i].computerGrade;
    }
    
    // обчислюємо середній бал по заданому предмету
    int totalGrade = 0;
    int numGrades = 0;
    for (int i = 0; i < numStudents; i++) {
        if (subject == "math") {
            totalGrade += students[i].mathGrade;
            numGrades++;
        } else if (subject == "physics") {
            totalGrade += students[i].physicsGrade;
            numGrades++;
        } else if (subject == "computer") {
            totalGrade += students[i].computerGrade;
            numGrades++;
        } else {
            cerr << "Error: invalid subject name" << endl;
            return 1;
        }
    }
    double averageGrade = static_cast<double>(totalGrade) / numGrades;
    
    // виводимо результати
    cout << "The average grade for " << subject << " is " << averageGrade << endl;
    
    // закриваємо файл
    inputFile.close();
    
    return 0;
}