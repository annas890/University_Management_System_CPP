University Management System (C++)

## Overview

The "University Management System" is a console-based application developed in "C++" that simulates basic university operations such as managing students, teachers, and courses.

This project was built as part of an "Object-Oriented Programming (OOP)" course to demonstrate the practical implementation of core OOP concepts.

---

## Features

* Add and manage student records
* Add and manage teacher records
* Create courses and assign instructors
* Enroll students in courses
* Search students by ID
* Update student email
* Display all system records

---

## OOP Concepts Implemented

This project applies all four pillars of Object-Oriented Programming:

* Encapsulation

   * Data members are private
   * Access controlled via getters and setters

* Abstraction

   * Implemented using an abstract base class (`Person`)

* Inheritance

   * `Student` and `Teacher` inherit from `Person`

* Polymorphism

   * Virtual function `display()` is overridden in derived classes

---

## Technologies Used

* C++ (Standard Library)
* Object-Oriented Programming (OOP)
* Console-based Interface

---

## Project Structure


├── OOP FinalProject Semester 3.cpp
├── README.md
```

---

##  How to Run

* Step 1: Compile the Program

```bash
g++ main.cpp -o ums
```

* Step 2: Run the Program

```bash
./ums
```

---

## Sample Menu

```
===== UNIVERSITY MANAGEMENT SYSTEM =====
1. Add Student
2. Add Teacher
3. Add Course & Assign Teacher
4. Enroll Student
5. View Records
6. Search Student
7. Update Email
0. Exit
```

---

## Learning Outcomes

* Strong understanding of OOP concepts
* Improved problem-solving and coding skills
* Experience in designing structured systems
* Hands-on practice with real-world logic implementation

---

## Future Improvements

* Add file handling (data persistence)
* Implement login/authentication system
* Upgrade to GUI-based application
* Use dynamic memory (linked lists / vectors)
* Add grading and attendance system

---

## Author

* Annas Islam
* Hatim Bhuranpur

---

## Contribution

Feel free to fork this repository and improve it. Suggestions and contributions are welcome!

---

## License

This project is for educational purposes only.
