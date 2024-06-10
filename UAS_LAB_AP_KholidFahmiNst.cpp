#include <iostream>
#include <vector>
#include <string>

// Define a struct to hold data about a student
struct Student {
    std::string name;
    int age;
    float grade;
};

// Function to create a new student
Student* createStudent(const std::string& name, int age, float grade) {
    Student* newStudent = new Student;
    newStudent->name = name;
    newStudent->age = age;
    newStudent->grade = grade;
    return newStudent;
}

// Function to print student details
void printStudent(const Student* student) {
    std::cout << "Name: " << student->name << "\n";
    std::cout << "Age: " << student->age << "\n";
    std::cout << "Grade: " << student->grade << "\n";
}

// Function to add a student to a vector of students
void addStudent(std::vector<Student*>& students, const std::string& name, int age, float grade) {
    Student* student = createStudent(name, age, grade);
    students.push_back(student);
}

// Function to print all students
void printAllStudents(const std::vector<Student*>& students) {
    for (const Student* student : students) {
        printStudent(student);
        std::cout << "-------------------\n";
    }
}

// Function to delete all students
void deleteAllStudents(std::vector<Student*>& students) {
    for (Student* student : students) {
        delete student;
    }
    students.clear();
}

int main() {
    // Vector to store student pointers
    std::vector<Student*> students;
    
    // Add some students
    addStudent(students, "Alice", 20, 90.5);
    addStudent(students, "Bob", 22, 85.3);
    addStudent(students, "Charlie", 21, 78.9);
    
    // Print all students
    printAllStudents(students);
    
    // Clean up
    deleteAllStudents(students);
    
    return 0;
}
