#include<iostream>
#include<string>
using namespace std;
class Student {
  private:
    int id;
    string name;
    // ... other student data members
  public:
    // ... student methods
};

class Teacher {
  private:
    int id;
    string name;
    Course* course; // the course this teacher teaches
    // ... other teacher data members
  public:
    void setMarks(Student* student, float marks) {
        // TODO: implement this method to set the marks for the given student
    }
    // ... other teacher methods
};

class Course {
  private:
    string name;
    Teacher* teacher;
    vector<Student*> students;
    // ... other course data members
  public:
    void enrollStudent(Student* student) {
        students.push_back(student);
    }
    void setTeacher(Teacher* teacher) {
        this->teacher = teacher;
    }
    void setMarks(Student* student, float marks) {
        teacher->setMarks(student, marks);
    }
    // ... other course methods
};

class Administrator {
  private:
    vector<Course*> courses;
    // ... other administrator data members
  public:
    void calculateCGPA(Student* student) {
        // TODO: implement this method to calculate the CGPA for the given student
    }
    // ... other administrator methods
};
With this implementation, each course has its own teacher and list of enrolled students. The setMarks method in the Teacher class is used to set the marks for a specific student in the teacher's assigned course. The setMarks method in the Course class simply forwards the call to the teacher's setMarks method.

The Administrator class has access to all the courses and can calculate the CGPA for a given student. The Teacher class only has access to the students in their assigned course and can set their marks