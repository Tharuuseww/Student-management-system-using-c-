#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    char address[100];
    char contactNumber[15];
    char grade[10];
    int indexNumber; // Changed "Roll No" to "Index Number"
    float marks;
};

struct Teacher {
    char name[50];
    char subject[50];
    char grade[10];
    char contactNumber[15];
};

void addStudent(Student students[], int& studentCount) {
    clrscr();
    cout << "Enter student details:" << endl;
    
    cout << "Name: ";
    cin.ignore();
    cin.getline(students[studentCount].name, sizeof(students[studentCount].name));
    
    cout << "Address: ";
    cin.getline(students[studentCount].address, sizeof(students[studentCount].address));

    cout << "Contact Number: ";
    cin.getline(students[studentCount].contactNumber, sizeof(students[studentCount].contactNumber));

    cout << "Grade: ";
    cin.getline(students[studentCount].grade, sizeof(students[studentCount].grade));
    
    cout << "Index Number: "; // Changed "Roll No" to "Index Number"
    cin >> students[studentCount].indexNumber; // Changed "Roll No" to "Index Number"
    
    cout << "Marks: ";
    cin >> students[studentCount].marks;
    
    studentCount++;
}

void addTeacher(Teacher teachers[], int& teacherCount) {
    clrscr();
    cout << "Enter teacher details:" << endl;

    cout << "Name: ";
    cin.ignore();
    cin.getline(teachers[teacherCount].name, sizeof(teachers[teacherCount].name));

    cout << "Subject: ";
    cin.getline(teachers[teacherCount].subject, sizeof(teachers[teacherCount].subject));

    cout << "Grade: ";
    cin.getline(teachers[teacherCount].grade, sizeof(teachers[teacherCount].grade));

    cout << "Contact Number: ";
    cin.getline(teachers[teacherCount].contactNumber, sizeof(teachers[teacherCount].contactNumber));
    
    teacherCount++;
}

void displayStudents(const Student students[], int studentCount, const char gradeFilter[]) {
    clrscr();
    cout << "Student List (Grade " << gradeFilter << "):" << endl;
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].grade, gradeFilter) == 0) {
            cout << "Name: " << students[i].name << endl;
            cout << "Address: " << students[i].address << endl;
            cout << "Contact Number: " << students[i].contactNumber << endl;
            cout << "Index Number: " << students[i].indexNumber << endl; // Changed "Roll No" to "Index Number"
            cout << "Marks: " << students[i].marks << endl << endl;
        }
    }
    cout << "Press any key to continue...";
    getch();
}

void displayTeachers(const Teacher teachers[], int teacherCount, const char gradeFilter[]) {
    clrscr();
    cout << "Teacher List (Grade " << gradeFilter << "):" << endl;
    for (int i = 0; i < teacherCount; i++) {
        if (strcmp(teachers[i].grade, gradeFilter) == 0) {
            cout << "Name: " << teachers[i].name << endl;
            cout << "Subject: " << teachers[i].subject << endl;
            cout << "Contact Number: " << teachers[i].contactNumber << endl << endl;
        }
    }
    cout << "Press any key to continue...";
    getch();
}

int main() {
    Student students[100];
    Teacher teachers[20];
    int studentCount = 0;
    int teacherCount = 0;
    char choice;

    while (1) {
        clrscr();
        cout << "School Management System" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Add Teacher" << endl;
        cout << "3. Display Students by Grade" << endl;
        cout << "4. Display Teachers by Grade" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                addStudent(students, studentCount);
                break;
            case '2':
                addTeacher(teachers, teacherCount);
                break;
            case '3':
                clrscr();
                cout << "Enter grade for student display: ";
                char gradeFilter[10];
                cin >> gradeFilter;
                displayStudents(students, studentCount, gradeFilter);
                break;
            case '4':
                clrscr();
                cout << "Enter grade for teacher display: ";
                char teacherGradeFilter[10];
                cin >> teacherGradeFilter;
                displayTeachers(teachers, teacherCount, teacherGradeFilter);
                break;
            case '5':
                exit(0);
            default:
                cout << "Invalid choice. Press any key to continue...";
                getch();
        }
    }

    return 0;
}
