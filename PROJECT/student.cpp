#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Course {
public:
    Course(string id) : id(id) {}
    static int numCourses;
    void updateMarks(string rollNo, int marks) {
        // Read the data for this course from file
        vector<string> rollNos;
        vector<int> marksList;
        ifstream inFile(id + ".txt");
        if (inFile.is_open()) {
            string line;
            while (getline(inFile, line)) {
                string rno;
                int m;
                istringstream iss(line);
                if (iss >> rno >> m) {
                    rollNos.push_back(rno);
                    marksList.push_back(m);
                }
            }
            inFile.close();
        }

        // Update the marks for the specified roll number
        bool found = false;
        for (int i = 0; i < rollNos.size(); i++) {
            if (rollNos[i] == rollNo) {
                marksList[i] = marks;
                found = true;
                break;
            }
        }

        // Write the updated data back to file
        ofstream outFile(id + ".txt");
        if (outFile.is_open()) {
            for (int i = 0; i < rollNos.size(); i++) {
                outFile << rollNos[i] << " " << marksList[i] << endl;
            }
            outFile.close();
        }

        if (found) {
            cout << "Marks updated successfully" << endl;
        } else {
            cout << "Roll number not found" << endl;
        }
    }


private:
    string id;
};

class Student {
public:
    Student(string rollNo) : rollNo(rollNo) {}

    void viewMarks() {
        // Read the data for all courses from file
        vector<string> courseIds;
        vector<int> marksList;
        ifstream inFile(rollNo + ".txt");
        if (inFile.is_open()) {
            string line;
            while (getline(inFile, line)) {
                string courseId;
                int marks;
                istringstream iss(line);
                if (iss >> courseId >> marks) {
                    courseIds.push_back(courseId);
                    marksList.push_back(marks);
                }
            }
            inFile.close();
        }

        // Display the marks
        for (int i = 0; i < courseIds.size(); i++) {
            cout << courseIds[i] << " " << marksList[i] << endl;
        }
    }
private:
    string rollNo;
};

class Teacher {
public:
    void updateMarksForCourse() {
        string courseId;
        cout << "Enter course id: "<< endl;
         cin >> courseId;
        Course c(courseId);
        string rollNo;
        cout << "Enter roll number: ";
        cin >> rollNo;
        int marks;
        cout << "Enter marks: ";
        cin >> marks;
        c.updateMarks(rollNo, marks);
    }
};

int Course::numCourses = 3;

int main() {
    
    Teacher t;
    
    t.updateMarksForCourse();
   

    return 0;
}
