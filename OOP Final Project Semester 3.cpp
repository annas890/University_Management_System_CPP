#include <iostream>
#include <string>
using namespace std;

// ================= PERSON (ABSTRACTION + ENCAPSULATION) =================
class Person {
private:
    int id;
    string name, email;

public:
    Person() {}
    Person(int i, string n, string e) {
        id = i;
        name = n;
        email = e;
    }

    // Getters (Encapsulation)
    int getId() const { return id; }
    string getName() const { return name; }
    string getEmail() const { return email; }

    void setEmail(string e) { email = e; }

    // Pure Virtual Function (Abstraction)
    virtual void display() const = 0;
};

// ================= STUDENT (INHERITANCE + POLYMORPHISM) =================
class Student : public Person {
private:
    string department;

public:
    Student() {}
    Student(int i, string n, string e, string d)
        : Person(i, n, e) {
        department = d;
    }

    void display() const override {
        cout << "Student ID: " << getId()
             << " | Name: " << getName()
             << " | Email: " << getEmail()
             << " | Dept: " << department << endl;
    }
};

// ================= TEACHER =================
class Teacher : public Person {
private:
    string department;

public:
    Teacher() {}
    Teacher(int i, string n, string e, string d)
        : Person(i, n, e) {
        department = d;
    }

    void display() const override {
        cout << "Teacher ID: " << getId()
             << " | Name: " << getName()
             << " | Email: " << getEmail()
             << " | Dept: " << department << endl;
    }
};

// ================= COURSE =================
class Course {
private:
    string code, title;
    Teacher* instructor;
    Student* enrolled[30];
    int enrollCount;

public:
    Course() {
        instructor = NULL;
        enrollCount = 0;
    }

    Course(string c, string t) {
        code = c;
        title = t;
        instructor = NULL;
        enrollCount = 0;
    }

    void assignTeacher(Teacher* t) {
        instructor = t;
    }

    void enrollStudent(Student* s) {
        if (enrollCount < 30) {
            enrolled[enrollCount++] = s;
        }
    }

    void display() const {
        cout << "\nCourse Code: " << code
             << "\nTitle: " << title << endl;

        if (instructor)
            cout << "Instructor: " << instructor->getName() << endl;
        else
            cout << "Instructor: Not Assigned\n";

        cout << "Enrolled Students: " << enrollCount << endl;
    }
};

// ================= MAIN =================
int main() {
    Student students[50];
    Teacher teachers[20];
    Course courses[20];

    int sCount = 0, tCount = 0, cCount = 0;
    int choice;

    do {
        cout << "\n===== UNIVERSITY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Add Teacher\n";
        cout << "3. Add Course & Assign Teacher\n";
        cout << "4. Enroll Student\n";
        cout << "5. View Records\n";
        cout << "6. Search Student\n";
        cout << "7. Update Email\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            int id; string name, email, dept;
            cout << "ID: "; cin >> id;
            cin.ignore();
            cout << "Name: "; getline(cin, name);
            cout << "Email: "; getline(cin, email);
            cout << "Dept: "; getline(cin, dept);

            students[sCount++] = Student(id, name, email, dept);
        }

        else if (choice == 2) {
            int id; string name, email, dept;
            cout << "ID: "; cin >> id;
            cin.ignore();
            cout << "Name: "; getline(cin, name);
            cout << "Email: "; getline(cin, email);
            cout << "Dept: "; getline(cin, dept);

            teachers[tCount++] = Teacher(id, name, email, dept);
        }

        else if (choice == 3) {
            string code, title;
            int tIndex;

            cin.ignore();
            cout << "Course Code: "; getline(cin, code);
            cout << "Title: "; getline(cin, title);

            courses[cCount] = Course(code, title);

            cout << "Assign Teacher Index: ";
            cin >> tIndex;

            if (tIndex >= 0 && tIndex < tCount)
                courses[cCount].assignTeacher(&teachers[tIndex]);

            cCount++;
        }

        else if (choice == 4) {
            int sIndex, cIndex;
            cout << "Student Index: "; cin >> sIndex;
            cout << "Course Index: "; cin >> cIndex;

            if (sIndex < sCount && cIndex < cCount)
                courses[cIndex].enrollStudent(&students[sIndex]);
        }

        else if (choice == 5) {
            cout << "\n--- STUDENTS ---\n";
            for (int i = 0; i < sCount; i++)
                students[i].display();

            cout << "\n--- TEACHERS ---\n";
            for (int i = 0; i < tCount; i++)
                teachers[i].display();

            cout << "\n--- COURSES ---\n";
            for (int i = 0; i < cCount; i++)
                courses[i].display();
        }

        else if (choice == 6) {
            int id;
            cout << "Enter ID: "; cin >> id;

            for (int i = 0; i < sCount; i++) {
                if (students[i].getId() == id) {
                    students[i].display();
                    break;
                }
            }
        }

        else if (choice == 7) {
            int id; string email;
            cout << "Enter ID: "; cin >> id;
            cin.ignore();
            cout << "New Email: "; getline(cin, email);

            for (int i = 0; i < sCount; i++) {
                if (students[i].getId() == id) {
                    students[i].setEmail(email);
                    cout << "Updated!\n";
                    break;
                }
            }
        }

    } while (choice != 0);

    return 0;
}