#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Define a class to hold a student's marks for a single course
class CourseMarks {
private:
    string courseID;
    float marks;
public:
    CourseMarks(string id, float m) : courseID(id), marks(m) {}
    string getCourseID() const { return courseID; }
    float getMarks() const { return marks; }
    void setMarks(float m) { marks = m; }
};

// Define a class to hold a student's marks for all courses in a single semester
class SemesterMarks {
private:
    vector<CourseMarks> courseMarks;
public:
    float calculateGPA() const {
        float totalMarks = 0.0;
        int numCourses = courseMarks.size();
        for (int i = 0; i < numCourses; i++) {
            totalMarks += courseMarks[i].getMarks();
        }
        return totalMarks / numCourses;
    }
    void addCourseMarks(string id, float marks) {
        courseMarks.push_back(CourseMarks(id, marks));
    }
    const vector<CourseMarks>& getCourseMarks() const { return courseMarks; }
};

// Define a class to hold a student's marks for all semesters
class StudentMarks {
private:
    vector<SemesterMarks> semesterMarks;
public:
    void addSemesterMarks(const SemesterMarks& sm) {
        semesterMarks.push_back(sm);
    }
    const vector<SemesterMarks>& getSemesterMarks() const { return semesterMarks; }
};

// Define a class to hold all students' marks
class CourseGrades {
private:
    vector<StudentMarks> studentMarks;
public:
    void addStudentMarks(const StudentMarks& sm) {
        studentMarks.push_back(sm);
    }
    const vector<StudentMarks>& getStudentMarks() const { return studentMarks; }
};

int main() {
    CourseGrades courseGrades;
    string courseID1, courseID2, courseID3;
    float marks1, marks2, marks3;
    // Add student 1's marks for semester 1
    StudentMarks student1Marks;
    SemesterMarks semester1Marks;

    cout<<"Enter the course id  1 and marks of student 1 for semester 1"<<endl;
    cin>>courseID1>>marks1;
    semester1Marks.addCourseMarks(courseID1, marks1);

    cout<<"Enter the course id  2 and marks of student 1 for semester 1"<<endl;
    cin>>courseID2>>marks2;
    semester1Marks.addCourseMarks(courseID2, marks2);

    cout<<"Enter the course id  3 and marks of student 1 for semester 1"<<endl;
    cin>>courseID3>>marks3;
    semester1Marks.addCourseMarks(courseID3, marks3);
    student1Marks.addSemesterMarks(semester1Marks);
    courseGrades.addStudentMarks(student1Marks);

    // Add student 2's marks for semester 1
    StudentMarks student2Marks;
    SemesterMarks semester2Marks;
    cout<<"Enter the course id  1 and marks of student 2 for semester 1"<<endl;
    cin>>courseID1>>marks1;
    semester2Marks.addCourseMarks(courseID1, marks1);
    cout<<"Enter the course id  2 and marks of student 2 for semester 1"<<endl;
    cin>>courseID2>>marks2;
    semester2Marks.addCourseMarks(courseID2, marks2);
    cout<<"Enter the course id  3 and marks of student 2 for semester 1"<<endl;
    cin>>courseID3>>marks3;
    semester2Marks.addCourseMarks(courseID3, marks3);
    student2Marks.addSemesterMarks(semester2Marks);
    courseGrades.addStudentMarks(student2Marks);

    // Add student 1's marks for semester 2
    SemesterMarks semester2Marks2;
    cout<<"Enter the course id  1 and marks of student 1 for semester 2"<<endl;
    cin>>courseID1>>marks1;
    semester2Marks2.addCourseMarks(courseID1, marks1);
    cout<<"Enter the course id  2 and marks of student 1 for semester 2"<<endl;
    cin>>courseID2>>marks2;
    semester2Marks2.addCourseMarks(courseID2, marks2);
    cout<<"Enter the course id  3 and marks of student 1 for semester 2"<<endl;
    cin>>courseID3>>marks3;
    semester2Marks2.addCourseMarks(courseID3, marks3);

    student1Marks.addSemesterMarks(semester2Marks2);

    // Display student 1's marks for course CSE102 in semester 1
    const vector<StudentMarks>& allStudentMarks = courseGrades.getStudentMarks();
    if (allStudentMarks.size() > 0) {
        cout<<"Enter student no you want to display"<<endl;
        int studentNo;
        cin>>studentNo;
        const vector<SemesterMarks>& semesterMarks = allStudentMarks[studentNo-1].getSemesterMarks();
       


    if (semesterMarks.size() > 0) {
      cout<<"Enter semester no you want to display"<<endl;
        int semesterNo;
            cin >> semesterNo;
        const vector<CourseMarks>& courseMarks = semesterMarks[semesterNo-1].getCourseMarks();
      
        cout<<"Enter course id you want to display"<<endl;
        string courseID;
        cin >> courseID;
        for (int i = 0; i < courseMarks.size(); i++) {
            if (courseMarks[i].getCourseID() == courseID) {
                cout << "Student "<< studentNo << " marks for course "<< courseID << "in semester " << semesterNo << courseMarks[i].getMarks() << endl;
                break;
            }
        }
    }
}

return 0;

}
