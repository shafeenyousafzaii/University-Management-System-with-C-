#include <iostream>
#include <string>
#include <vector>
using namespace std;

class dateType
{
int date;
int month;
int year;

public:

   dateType(int d=1,int m=1 , int y=2000);//KAshif
   void setDate(int d ,int m ,int y);
   void getDate(int &d, int &m ,int &y)const;

};

enum status{present,absent,late};//Kashif
class attendanceType
{
dateType date;//KAshif
status  _status;//KAshif

public :

  attendanceType(int d=1,int m=1 , int y=2000,status s=present);//KAshif
  void setStatusOnly(char s);
  void setDateOnly(int d,int m, int y);//KAshif
  void getStatus(int &d,int &m, int &y,char &s)const;

};

class studentType
{
string name;
string ID;
string email;
string father_name;
string address;
int semester_no;
string cgpa;
vector<attendanceType> attendance;


public:

  studentType(string s="" , string id=0, string e="", string f_name="", string add="", int no=0);
  void set_data(string s , string id, string e, string f_name, string add, int no);

  void get_data(string &s , string &id, string &e, string &f_name, string &add, int &no)const; 
  void show_attendance_details(int d,int m,int y);
  void set_attendance_status( int no, char status);
  void set_attendance_date( int no, int d, int m, int y);
  void set_cgpa(string c);
  string get_cgpa();

};


class courseType
{
vector<string> courses_enrolled;
vector<float> course_wise_marks;
vector<int>total_no_of_courses;
vector<studentType> student;
string courseId;

public:

  courseType();
   vector<studentType>& get_student() {
        return student;
    }

    void set_student(const vector<studentType>& studentData) {
        student = studentData;
    }
  void set_courses(vector<string> &c, int no);
  string get_courses()const;
  void set_marks(vector<float> &m, int no);
  float get_marks()const;
  // void set_course_wise_attendance(vector<string> &s, int no);
  void set_courseId(string c);
  string get_courseId()const;
  // string get_course_wise_attendance()const;
 studentType get_student_data()const;
  void show_courses_enrolled()const;
  void show_course_wise_marks()const;
  void show_course_wise_attendance()const;
   void set_marks_value(int student_no, float marks_value);


};


class Accounts
{
float HOURLY_RATE;
int total_working_hours;
 float monthlySalary;

public:
   Accounts();
   void set_rate(float r);
   float get_rate()const;
   void set_total_working_hours(int t);
   int get_total_working_hours()const;
   void set_monthlySalary(float mSalary);
   float get_monthlySalary()const;
   void calculate_salary();
};


class employeeType
{ 
protected:
string name;
string ID;
string email;
string address;
string designation;
Accounts account;
vector<courseType> courses;


public:
   employeeType();
   void set_data(string s , string id, string e, string add, string des);
   void get_data(string &s , string &id, string &e, string &add, string &des);
   void getmarks(int SR_NO)const;
   void show_payments_details();
};


class facultyMemberType : public employeeType
{ 
  string courseId;

vector<courseType> courses;

public:
   facultyMemberType();
   void set_marks(vector<courseType> &c, int student_no,  string cId ,float marks_value);
   void set_attendance(vector<courseType> &c, int student_no, string cId ,string status);
  

};


class academicMemberType : public employeeType
{
 vector<float>marks;
 vector<string>grade;
 vector<courseType> course;
 vector<studentType> student;

public:
  academicMemberType();  
  void set_marks(vector<float> &m, int no);
    float get_marks(vector<float> &m, int &no);
    friend void set_grades(vector<string> &g, int no);
    string get_grades(vector<string> &g, int &no);
    void set_cgpa(float c);
    float get_cgpa();
    void set_attendance(vector<string> &s, int no);
    void Calculate_cgpa();
  void update_cgpa();

};

