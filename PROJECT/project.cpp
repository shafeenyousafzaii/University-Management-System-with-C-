#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
enum status{P,A,L};
class Attendance
{
private:
    int date;
    int month;
    int year;
    string cdate;
    status att;


public:
    Attendance();
    void updateAttendance(string rNO,char status)
    {
        setID(cdate);
        vector<string> rollno;
        vector<char> statuss;
        ifstream infile(cdate +".txt" );
        if(infile.is_open())
       {
        string line;
        while(getline(infile,line))
        {
            string rno;
            char c;
            istringstream iss(line);
            if(iss >> rno >> c)
            {
                rollno.push_back(rno);
                statuss.push_back(c);
            }
        }
        infile.close();
       }
     bool found=false;
     for(int i = 0 ; i < rollno.size();i++)
     {
        if (rollno[i]== rNO)
        {
            statuss[i] = status;
            found = true;
            break;
        }
        
     }
     ofstream outFile(cdate+".txt");
     if(outFile.is_open())
     {
       for (int i = 0; i < rollno.size(); i++)
       {
         outFile << rollno[i] << " " << statuss[i] << endl;

       }
       outFile.close();
       
     }
     if(found)
     {
        cout<<"Attendance Updated Successfully" << endl;
     }
     else
    {
        cout<<"Roll No not found " << endl;
    }

    }
    void setID(string s)
    {
        cdate=s;
    }
    ~Attendance();
};

Attendance::Attendance(/* args */)
{
  
}

Attendance::~Attendance()
{
}

// void Attendance::

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
   
   void viewMarks(string courseId) {
    // Read the data for this course from file
    vector<string> rollNos;
    vector<int> marksList;
    ifstream inFile(courseId + ".txt");
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

    // Display the marks and student info for the specified roll number
    bool found = false;
    ifstream studentFile("students.txt");
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

    for (int i = 0; i < rollNos.size(); i++) {
        if (rollNos[i] == rollNo) {
            cout << courseId << " Marks: " << marksList[i] << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Roll number not found" << endl;
    }
}

private:
    string rollNo;
    string name;
    string program;
    string section;
    string semester;
    int Batch;
    string email;
    string phone;
    string father_name;

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
     
       Student s(rollNo);
    s.viewMarks(courseId);

    }
};

int Course::numCourses = 3;

int main() {

 while (1)
 {
  
    cout<<"Enter 1 for student and 2 for teacher and 3 for exit "<<endl;
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
        cout << "Enter course ID: "<< endl;
        cin >> courseId;
        cout << "Enter roll number: ";
        cin >> rollNo;
    
  
        Student student;
        student.setRollNo(rollNo);
        student.viewMarks(courseId);
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
         Teacher t;
    
         t.updateMarksForCourse();
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
        break;
     }

    else
     {
        cout<<"Invalid choice"<<endl;
     }
    
    
 }
    return 0;
}