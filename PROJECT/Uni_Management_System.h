#include<iostream>
using namespace std;

class dateType
{
int date;
int month;
int year;
public:
void setDate(int d ,int m ,int y);
void getDate(int &d, int &m ,int &y);

};

class attendanceType
{
dateType date[30];
string status;
public :
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
attendanceType attendance[30];
public:
void set_data(string s , string id, string e, string f_name, string add, int no);
void get_data(string &s , string &id, string &e, string &f_name, string &add, int &no); 
};

class courseType
{
string courses_enrolled[5];
float course_wise_marks[5];
int total_no_of_courses;
studentType student[30];
public:
void set_courses(string c[5], int no);
string get_courses(string c[5], int &no);
void set_marks(float m[5], int no);
float get_marks(float m[5], int &no);
void set_course_wise_attendance(string s[5], int no);
void change_courses_enrolled(string c[5], int no);

};

class academicRecordType
{
float marks[5];
string grade[5];
float cgpa;
courseType course[5];
public:
void set_marks(float m[5], int no);
float get_marks(float m[5], int &no);
void set_grades(string g[5], int no);
string get_grades(string g[5], int &no);
void set_cgpa(float c);
float get_cgpa();
void set_attendance(string s[5], int no);
void Calculate_cgpa();
};

class Accounts
{
float rate;
int total_working_hours;
public:
void set_rate(float r);
float get_rate();
void set_total_working_hours(int t);
int get_total_working_hours();
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
courseType courses[5];
public:
void set_data(string s , string id, string e, string add, string des);
void get_data(string &s , string &id, string &e, string &add, string &des);
void show_payments_details();
};

class facultyMemberType : public employeeType
{
int credit_hours;
courseType courses[5];
public:
void set_marks(courseType c[5], int student_no,float marks_value);
void set_attendance(courseType c[5], int student_no,string status);

};

class academicMemberType : public employeeType
{
academicRecordType academic_record[5];
public:
void set_marks(courseType c[5], int student_no,float marks_value);
void set_attendance(courseType c[5], int student_no,string status);
void update_cgpa();
};

