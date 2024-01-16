#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int day =0 , int month =0 , int year =0) {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    void display() const {
        cout << day << "/" << month << "/" << year;
    }
};

class Attendance {
private:
    Date date;
    string status;

public:
    Attendance(Date date, string status) {
        this->date = date;
        this->status = status;
    }

    Date getDate() const { return date; }
    string getStatus() const { return status; }
};

class Employee {
protected:
    string name;
    int empId;

public:
    Employee(string name, int empId) {
        this->name = name;
        this->empId = empId;
    }

    string getName() const { return name; }
    int getEmpId() const { return empId; }
};




class Course {
private:
    string courseName;
    int marks;
    float creditHours;
     vector<Attendance> attendanceRecords;

public:
    Course(string courseName, int marks, float creditHours) {
        this->courseName = courseName;
        this->marks = marks;
        this->creditHours = creditHours;
    }

    string getCourseName() const { return courseName; }
    int getMarks() const { return marks; }
    float getCreditHours() const { return creditHours; }

    void updateMarks(int newMarks) {
        marks = newMarks;
    }

    void addAttendance(Date date, string status) {
        Attendance attendance(date, status);
        attendanceRecords.push_back(attendance);
    }

    void display() const {
        cout << "Course: " << courseName << endl;
        cout << "Attendance Records: " << endl;
        for (const Attendance& attendance : attendanceRecords) {
            cout << "Date: ";
            attendance.getDate().display();
            cout << ", Status: " << attendance.getStatus() << endl;
        }
    }
};


class Student {
private:
    string name;
    vector<Course> courses;

public:
    Student(string name) {
        this->name = name;
    }

    string getName() const { return name; }

    void addCourse(string courseName,int marks ,int creditHrs) {
        Course course(courseName,marks,creditHrs);
      courses.push_back(course);
    }

    void updateAttendance(string courseName, Date date, string status) {
        for (Course& course : courses) {
            if (course.getCourseName() == courseName) {
                course.addAttendance(date, status);
                break;
            }
        }
    }

    void display() const {
        cout << "Student: " << name << endl;
        for (const Course& course : courses) {
            course.display();
        }
    }
};

int main() {
    string studentName;
    cout << "Enter student name: ";
    cin >> studentName;

    Student student(studentName);

    int numCourses;
    cout << "Enter number of courses: ";
    cin >> numCourses;

    for (int i = 0; i < numCourses; i++) {
        string courseName;
        int marks,creditHrs;
        cout << "Enter course name " << i + 1 << ": ";
        cin >> courseName;
        
        student.addCourse(courseName,marks,creditHrs);

    }

    int numAttendanceRecords;
    cout << "Enter number of attendance records to update: ";
    cin >> numAttendanceRecords;

    for (int i = 0; i < numAttendanceRecords; i++) {
        string courseName;
        cout << "Enter course name for attendance record " << i + 1 << ": ";
        cin >> courseName;  

    Date date;
    int day, month, year;
    cout << "Enter date for attendance record " << i + 1 << ":" << endl;
    cout << "Enter day: ";
    cin >> day;
    cout << "Enter month: ";
    cin >> month;
    cout << "Enter year: ";
    cin >> year;
    date = Date(day, month, year);

    string status;
    cout << "Enter attendance status (P/A/L): ";
    cin >> status;

    student.updateAttendance(courseName, date, status);
}

student.display();

return 0;

}

