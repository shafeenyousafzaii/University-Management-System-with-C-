#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

class Date {
    friend class academicMember;
    int day;
    int month;
    int year;
public:
    Date(int day = 0, int month = 0, int year = 0) {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    void setDay(int day) {
        this->day = day;
    }

    void setMonth(int month) {
        this->month = month;
    }

    void setYear(int year) {
        this->year = year;
    }

    int getDay() {
        return day;
    }

    int getMonth() {
        return month;
    }

    int getYear() {
        return year;
    }
};

class Course {
 friend class Student;
 friend class Teacher;
 friend class academicMember;

    string id;
    int marks;
public:
    Course(string id) {
        this-> id = id;
    }
  
    void updateAttendance(string rollNo,Date d,char status)
    {
        vector<string> rollNos;
        vector<int> days;
        vector<int> months;
        vector<int> years;
        vector<char> statuses;

        ifstream inFile(id + ".txt");
        if (inFile.is_open()) {
            string line;
            while (getline(inFile, line)) {
                string rno;
                int d;
                int m;
                int y;
                char s;
                istringstream iss(line);
                if (iss >> rno >> d >> m >> y >> s) {
                    rollNos.push_back(rno);
                    days.push_back(d);
                    months.push_back(m);
                    years.push_back(y);
                    statuses.push_back(s);
                }
            }
            inFile.close();
        }

        bool found = false;
        for (int i = 0; i < rollNos.size(); i++) {
            if (rollNos[i] == rollNo && days[i] == d.getDay() && months[i] == d.getMonth() && years[i] == d.getYear()) {
                
                statuses[i] = status;
                found = true;
                break;
            }
        }

        ofstream outFile(id + ".txt");
        if (outFile.is_open()) {
            for (int i = 0; i < rollNos.size(); i++) {
                outFile << rollNos[i] << " " << days[i] << " " << months[i] << " " << years[i] << " " << statuses[i] << endl;

            }
            outFile.close();
        }

        if (found) {
            cout << "Attendance updated successfully" << endl;

        } else {
            cout << "Roll number not found" << endl;
        }
    }

    void updateMarks(string rollNo, int marks, string grade) {
        vector<string> rollNos;
        vector<int> marksList;
        vector<string> grades;

       
            ifstream inFile( id + ".txt");
            if (inFile.is_open()) {
                string line;
                while (getline(inFile, line)) {
                    string rno;
                    int m;
                    string g;
                    istringstream iss(line);
                    if (iss >> rno >> m >> g) {
                        rollNos.push_back(rno);
                        marksList.push_back(m);
                        grades.push_back(g);
                    }
                }
                inFile.close();
            }

            
            bool found = false;
            for (int i = 0; i < rollNos.size(); i++) {
                if (rollNos[i] == rollNo) {
                    marksList[i] = marks;
                    grades[i] = grade;
                    found = true;
                    break;
                }
            }

           
            ofstream outFile(id + ".txt");
            if (outFile.is_open()) {
                for (int i = 0; i < rollNos.size(); i++) {
                    outFile << rollNos[i] << " " << marksList[i] << " "<< grades[i] << endl;

                }
                outFile.close();
            }

            if (found) {
                cout << "Marks updated successfully" << endl;

            } else {
                cout << "Roll number not found" << endl;
            }
        
    }

   


};


class Student {

       string rollNo;
    string name;
    string program;
    string section;
    string semester;
    int Batch;
    string email;
    string phone;
    string father_name;
   vector<Course> courses;
   friend class Teacher;

public:
    Student(string rollNo = "",string name = "",string program = "",string section = "",string semester = "",int Batch = 0,string email = "",string phone = "",string father_name = "") {
        this->rollNo = rollNo;
        this->name = name;
        this->program = program;
        this->section = section;
        this->semester = semester;
        this->Batch = Batch;
        this->email = email;
        this->phone = phone;
        this->father_name = father_name;


    }

    void setRollNo(string rollNo) {
        this->rollNo = rollNo;
    }
   
   
   void displayInfo() {
   
   
 
    bool found = false;
    ifstream studentFile("C:\\Users\\Shafeen\\Documents\\My-all-programs--\\PROJECT\\1 Number file\\Backup\\THEME 1-20230510T165254Z-001\\THEME 1\\students.txt");
    if (studentFile.is_open()) {
        string line;
        while (getline(studentFile, line)) {
            string rno, F_name, L_name, program, section, semester, email, phone, father_F_name,father_L_name;
            istringstream iss(line);
            if (iss >> rno >> F_name >> L_name >> program >> section >> semester >> email >> phone >> father_F_name >>father_L_name) {
                if (rno == rollNo) {
                    cout << "Roll No: " << rno << endl;
                    cout << "Name: " << F_name <<" "<< L_name << endl;
                    cout << "Program: " << program << endl;
                    cout << "Section: " << section << endl;
                    cout << "Semester: " << semester << endl;
                    cout << "Email: " << email << endl;
                    cout << "Phone: " << phone << endl;
                    cout << "Father Name: " << father_F_name << " " <<father_L_name<< endl;
                    found = true;
                    break;
                }
            }
        }
        studentFile.close();
    }


    if (!found) {
        cout << "Roll number not found" << endl;
    }
}

 
};
class employee
{  protected:
    string name;
    string id;
    string email;
    string phone;
    
    string department;
    public:
  //


};


  class Teacher : public employee{
    vector<Course> courses;
    vector<Course> coursesAttendance;
    
public:
  
      void updateMarksForCourse() {
        string courseId;
      
        cout << "Enter course id: " << endl;
        cin >> courseId;
        Course c(courseId);

        string rollNo;
        cout << "Enter roll number: ";
        cin >> rollNo;

        int marks;
        string grade;
        cout << "Enter marks: ";
        cin >> marks;
        cout << "Enter grade: ";
        cin >> grade;


     for(int  i = 0 ;i < courses.size();i++){
        courses[i].updateMarks(rollNo, marks, grade);
    }
      }
    
    void updateAttendanceForCourse() {
        string courseId;
        cout << "Enter course id: " << endl;
        cin >> courseId;
        Course c(courseId);

        string rollNo;
        cout << "Enter roll number: ";
        cin >> rollNo;

        cout << "Enter date: " << endl;
        int day, month, year;
        cout << "Enter day: ";
        cin >> day;
        cout << "Enter month: ";
        cin >> month;
        cout << "Enter year: ";
        cin >> year;
        Date date(day, month, year);
        char status;
        cout << "Enter status: ";
        cin >> status;

        for (int i = 0; i < coursesAttendance.size(); i++) {
            coursesAttendance[i].updateAttendance(rollNo, date, status);
        }
    }
    void assignCourses(Course c1, Course c2) {
        courses.push_back(c1);
        courses.push_back(c2);
    }
    void assignCoursesAttendance(Course c1, Course c2) {
        coursesAttendance.push_back(c1);
        coursesAttendance.push_back(c2);
    }
    void display()
    {
    }
};

class academicMember:public employee{
    vector<Course> courses;
    vector<pair<string, vector<int>>> marks;
    vector<pair<string, vector<int>>> creditsHours;
    vector<pair<string, vector<string>>> grades;
    vector<pair<string, vector<pair<Date, char>>>> attendance;

 
public:
    void assignCourses(const Course& c1, const Course& c2, const Course& c3, const Course& c4, const Course& c5, const Course& c6) {
     
        courses.push_back(c1);
        courses.push_back(c2);
        courses.push_back(c3);
        courses.push_back(c4);
        courses.push_back(c5);
        courses.push_back(c6);
        
    }

    void storeMarks(const string& rollNo) {
        for (const Course& course : courses) {
            vector<int> marksList;
            vector<int> creditsHoursList;
            vector<string> gradesList;

            ifstream inFile(course.id + ".txt");
            if (inFile.is_open()) {
                string line;
                while (getline(inFile, line)) {
                    string rno;
                    int m;
                    int c;
                    string g;
                    istringstream iss(line);
                    if (iss >> rno >> m >> c >> g) {
                        if (rno == rollNo) {
                            marksList.push_back(m);
                            creditsHoursList.push_back(c);
                            gradesList.push_back(g);
                        }
                    }
                }
                inFile.close();
            }

            if (!marksList.empty()) {
                marks.push_back(make_pair(course.id, marksList));
                creditsHours.push_back(make_pair(course.id, creditsHoursList));
                grades.push_back(make_pair(course.id, gradesList));

            }
        }
    }

        
   
    void viewMarksAndGrades() 
    {
        for (int i = 0; i < marks.size(); i++) {
            cout << "Course ID: " << marks[i].first << endl;
            cout << "Marks: ";
            for (int j = 0; j < marks[i].second.size(); j++) {
                cout << marks[i].second[j] << " ";
            }
            cout << endl;

            cout << "Credits Hours: ";
            for (int j = 0; j < creditsHours[i].second.size(); j++) {
                cout << creditsHours[i].second[j] << " ";
            }
            cout << endl;

            cout << "Grades: ";
            for (int j = 0; j < grades[i].second.size(); j++) {
                cout << grades[i].second[j] << " ";
            }
            cout << endl;
        }


    }
void calculateGPA() {
    double totalCredits = 0;
    double totalGradePoints = 0;

    for (int i = 0; i < marks.size(); i++) {
        string courseId = marks[i].first;
        vector<int>& marksList = marks[i].second;
        vector<int>& creditsHoursList = creditsHours[i].second;
        vector<string>& gradesList = grades[i].second;

        for (int j = 0; j < marksList.size(); j++) {
            int mark = marksList[j];
            int creditsHours = creditsHoursList[j];
            string grade = gradesList[j];

            double gradePoints = 0.0;
           
            if (grade == "A" || grade == "A+") {
                gradePoints = 4.0;
            } else if (grade == "B" || grade == "B+") {
                gradePoints = 3.0;
            } else if (grade == "C" || grade == "C+") {
                gradePoints = 2.0;
            } else if (grade == "D" || grade == "D+") {
                gradePoints = 1.0;
            } else if (grade == "F") {
                gradePoints = 0.0;
            }

            totalCredits += creditsHours;
            totalGradePoints += (gradePoints * creditsHours);
        }
    }

    if (totalCredits > 0) {
        double gpa = totalGradePoints / totalCredits;
        cout << "GPA: " << gpa << endl;
    } else {
        cout << "No credits found." << endl;
    }
}

  
    void display()
    {
     

    }


       
};


void assignCourses(academicMember& member)
{
    
        Course c1("CS1001");
        Course c2("MT1003");
        Course c3("EE1002");
        Course c4("CS1002");
        Course c5("IS1004");
        Course c6("MT1005");

        member.assignCourses(c1,c2,c3,c4,c5,c6);
}

int main() {

employee *e1[2];
e1[0] = new Teacher();
e1[1] = new academicMember();

 while (1)
 {
  
    cout<<"Enter 1 for student and 2 for teacher and 3 for academicMember and 4 for exit "<<endl;
    int choice;
    cin>>choice;

    if(choice == 1)
     { 
      string courseId;
      string rollNo;
      string name;

     while(1)
      {
       int choice2;
       cout<<"Enter 1 for student info and 2 for exit"<<endl;
       cin>>choice2;

       if(choice2 == 1)
       {
       
        cout << "Enter roll number: ";
        cin >> rollNo;
        
    
         Student student;
        student.setRollNo(rollNo);
        student.displayInfo();
         academicMember member;
        
        assignCourses(member);
     
        member.storeMarks(rollNo);
        member.viewMarksAndGrades();
        member.calculateGPA();
       
     
       

      

        
       

      
       }

       else if(choice2 == 2)
       {
        break;
       }

       else
       {
        cout<<"Invalid choice"<<endl;
        }
      }
     }

    else if(choice == 2)
     {
        
      while(1)
      {
        
       int choice3;
       cout<<"Enter 1 for update marks and 2 for exit"<<endl;
       cin>>choice3;

       if(choice3 == 1)
       {
         Teacher t1, t2, t3;
         Course c1("CS1001");
         Course c2("MT1003");
         Course c3("EE1002");
         Course c4("CS1002");
        Course c5("IS1004");
        Course c6("MT1005");
      //  e1[0]->display();

         t1.assignCourses(c1,c2);
        t2.assignCourses(c3,c4);
        t3.assignCourses(c5,c6);
         Course c1A("CS1001Attendance");
         Course c2A("MT1003Attendance");
         t1.assignCoursesAttendance(c1A,c2A);
        

         t1.updateMarksForCourse();
         t1.updateAttendanceForCourse();
        //   t2.updateMarksForCourse();
          //  t2.updateAttendanceForCourse();
           // t3.updateMarksForCourse();
          //  t3.updateAttendanceForCourse();



        }  

        else if(choice3 == 2)
        {
        break;
        }

        else
        {
        cout<<"Invalid choice"<<endl;
        }
      }
     }

    else if(choice == 3)
     {
        academicMember member;
       // e1[1]->display();
        Course c1("CS1001");
        Course c2("MT1003");
        Course c3("EE1002");
        Course c4("CS1002");
        Course c5("IS1004");
        Course c6("MT1005");

        member.assignCourses(c1,c2,c3,c4,c5,c6);
     


     }
    
    else if(choice == 4)
     {
        break;
     }
    else
     {
        cout<<"Invalid choice"<<endl;
     }
    
    
 }
    return 0;
}