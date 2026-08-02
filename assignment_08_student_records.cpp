// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

;

struct Student
{
    string name;
    string id;
    vector<int> scores;
};

vector<Student> students;

// Function to add a student
void addStudent()
{
    Student student;

    cout << "Student name: ";
    cin >> student.name;

    cout << "Student ID: ";
    cin >> student.id;

    int number;
    cout << "How many scores? ";
    cin >> number;

    for (int i = 0; i < number; i++)
    {
        int score;
        cout << "Enter score: ";
        cin >> score;

        student.scores.push_back(score);
    }

    students.push_back(student);

    cout << "Student added." << endl;
}

// Function to display all students
void displayStudents()
{
    if (students.empty())
    {
        cout << "No students found." << endl;
    }
    else
    {
        for (Student student : students)
        {
            int total = 0;

            for (int score : student.scores)
            {
                total += score;
            }

            double average = (double)total / student.scores.size();

            cout << "Name: " << student.name << endl;
            cout << "ID: " << student.id << endl;

            cout << "Scores: ";
            for (int score : student.scores)
            {
                cout << score << " ";
            }

            cout << endl;

            cout << "Average: " << fixed << setprecision(2) << average << endl;
            cout << "---------------------" << endl;
        }
    }
}

// Function to calculate average score of a student
void averageScore()
{
    string studentID;

    cout << "Enter student ID: ";
    cin >> studentID;

    for (Student student : students)
    {
        if (student.id == studentID)
        {
            int total = 0;

            for (int score : student.scores)
            {
                total += score;
            }

            double average = (double)total / student.scores.size();

            cout << "Average score: "
                 << fixed << setprecision(2)
                 << average << endl;

            return;
        }
    }

    cout << "Student not found." << endl;
}

// Menu function
void menu()
{
    while (true)
    {
        cout << "\nSTUDENT RECORD SYSTEM" << endl;
        cout << "1. Add student" << endl;
        cout << "2. Display students" << endl;
        cout << "3. Calculate average" << endl;
        cout << "4. Quit" << endl;

        string choice;

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == "1")
        {
            addStudent();
        }
        else if (choice == "2")
        {
            displayStudents();
        }
        else if (choice == "3")
        {
            averageScore();
        }
        else if (choice == "4")
        {
            cout << "Goodbye!" << endl;
            break;
        }
        else
        {
            cout << "Invalid choice." << endl;
        }
    }
}

int main()
{
    menu();

    return 0;
}