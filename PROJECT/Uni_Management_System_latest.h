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

   dateType();
   void setDate(int d ,int m ,int y);
   void getDate(int &d, int &m ,int &y);

};


class attendanceType
{
 vector<dateType> date;
 enum status{present,absent,leave};
 

public :

  attendanceType();
  void setStatus(string s);
  string getStatus();

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
// vector<attendanceType> attendance;


public:

  studentType();
  void set_data(string s , string id, string e, string f_name, string add, int no);
  void get_data(string &s , string &id, string &e, string &f_name, string &add, int &no); 
  void show_attendance_details();
  void set_attendance_status(vector<attendanceType> &a, int no, string status);
  void set_attendance_date(vector<attendanceType> &a, int no, int d, int m, int y);
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
  string get_courses();
  void set_marks(vector<float> &m, int no);
  float get_marks();
  void set_course_wise_attendance(vector<string> &s, int no);
  void set_courseId(string c);
  string get_courseId();
  string get_course_wise_attendance();
 studentType get_student_data();
  void show_courses_enrolled();
  void show_course_wise_marks();
  void show_course_wise_attendance();
   void set_marks_value(int student_no, float marks_value);


};

class Accounts
{
float HOURLY_RATE;
int total_working_hours;
 float monthlySalary;

public:
   Accounts(float HR=0,int tWH=0,int MS=0   );
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
  // void set_marks(vector<float> &m, int no);
  //   float get_marks(vector<float> &m, int &no);
  //   void set_grades(vector<string> &g, int no);
  //   string get_grades(vector<string> &g, int &no);
    void set_cgpa(float c);
    float get_cgpa();
    void Update_attendance(vector<string> &s, int no);
    void Calculate_cgpa();
  void update_cgpa();

};

