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
 friend class  academicMemberType;
   dateType(int d=1,int m=1 , int y=2000){
      setDate(d, m, y);
}
void dateType::setDate(int d, int m, int y)
{
    if (d >= 1 && m >= 1 && y >= 2000)
    {
        date = d;
        month = m;
        year = y;
    }
    else
        cout << "Invalid Date/Month/Year.Please Check";
   }
   void setDate(int d ,int m ,int y);
   void getDate(int &d, int &m ,int &y)const;

};

enum status{present,absent,late};

class attendanceType
{
dateType date;
status  _status;
public :

  attendanceType(int d=1,int m=1 , int y=2000,status s=present): date(d, m, y)
{
    this->_status = s;
}
void setStatusOnly(char s)
{
    if (s == 'P' || s == 'p')
        _status = present;
    else if (s == 'A' || s == 'a')
        _status = absent;
    else if (s == 'L' || s == 'l')
        _status = late;
}

  
  void setDateOnly(int d,int m, int y){
      date.setDate(d, m, y);
  }
  void getStatus(int &d,int &m, int &y,char &s)const
  {
     int date;
    int month;
    int year;

    this->date.getDate(date, month, year);

    d = date;
    m = month;
    s = year;

    if (_status == present)
        s = 'P';
    else if (_status == absent)
        s = 'A';
    else if (_status == late)
        s = 'L';
  }

};

class studentType
{
string name;
string ID;
string email;
string father_name;
string address;
int semester_no;
float cgpa;
vector<float> marks;
vector<string> grade;
vector<float>credit_hours;
int total_credit_hours;
int no_of_courses;
vector<attendanceType> attendance;
float points;
float total_points = 0.0;



public:

  studentType(string s="" , string id=0, string e="", string f_name="", string add="", int no=0)
  {
     set_data(s,id,e,f_name,add,no);
  }
  void set_data(string s , string id, string e, string f_name, string add, int no){
     name=s;
    ID=id;
    email=e;
    father_name=f_name;
    address=add;
    semester_no=no;
  }
  void get_data(string &s , string &id, string &e, string &f_name, string &add, int &no)const{

    s=name;
    id=ID;
    e=email;
    f_name=father_name;
    add=address;
    no=semester_no;
  }
  void show_attendance_details(int d,int m,int y){
    int check=0;
    int date;
    int month;
    int year;
    char status;

    for (auto i = attendance.begin() ; i != attendance.end() ; i++)
    {
        i->getStatus(date,month,year,status);
        if (date==d && month==m && year==y)
        {
            cout<<"\nAttendence of the "<<name<<" of Date "<<date<<"/"<<month<<"/"<<year<<" is "<<status<<endl;
            check=1;
            break;
        }
    }
    if (!check)
        cout<<"\nAttenence record of this date is not found."<<endl;
  }
  void set_attendance_status( int no, char status){

    attendance[no].setStatusOnly(status);
  }
  void set_attendance_date( int no, int d, int m, int y){
     attendance[no].setDateOnly(d,m,y);
  }

  void set_marks( int no,float m)
  {
    marks[no] = m;
    

  }
 
  

  void set_gpa()
  {
  
      for(int i = 0 ; i < grade.size(); i++)
      {
        if(marks[i] >= 90 )
        {
            grade[i] = "A+";
            points = 4.0;
        }

        else if(marks[i] >= 80 && marks[i] < 90)
        {
            grade[i] = "A";
            points = 4.0;
        }
        else if(marks[i] >= 70 && marks[i] < 80)
        {
            grade[i] = "B";
            points = 3.0;
        }
        else if(marks[i] >= 60 && marks[i] < 70)
        {
            grade[i] = "C";
            points = 2.0;
        }
        else if(marks[i] >= 50 && marks[i] < 60)
        {
            grade[i] = "E";
              points = 1.0;
        }
        else 
        {
            grade[i] = "F";
            points = 0.0;
        }  
        
        total_points += points*credit_hours[i];
        total_credit_hours +=credit_hours[i];


        
 
   
  }
    cgpa = total_points/total_credit_hours;
 
  }
  
  float get_cgpa(){
    
    return cgpa;
  }

void showResult()
{
  for(int i = 0 ; i < marks.size(); i++)
  {
    cout<< "Marks of course"<< i+1 << marks[i] << endl;
  }

  cout<<"CGPA ="<<cgpa<<endl;
}


};


class courseType
{
vector<string>courses_enrolled ;
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
  void set_courses(vector<string> &c, int no){
      
  }
  string get_courses(){

  }
  void set_marks(float m, int no){

    for(int i = 0 ; i < student.size(); i++)
    {
        student[i].set_marks(no,m);
  }
  }


  void set_course_wise_attendance(int no,char c){
    for(int i = 0 ; i < student.size(); i++)
    {
        student[i].set_attendance_status(no,c);
  }
  }
  void set_courseId(string c){
    courseId = c;
  }
  string get_courseId(){
    return courseId;
  }

 

  void show_courses_enrolled(){
   for(int i = 0 ; i < courses_enrolled.size();i++)
   {
    cout<< courses_enrolled[i] << endl;
   }
  }
  
  void show_course_wise_marks();
 
  
  void show_course_wise_attendance();
  


};

class Accounts
{
float HOURLY_RATE;
int total_working_hours;
 float monthlySalary;

public:
   Accounts()
   {
  float HOURLY_RATE = 0 ;
   int total_working_hours = 0;
   float monthlySalary;
   }
   void set_rate(float r){

    HOURLY_RATE = r;
   }
   float get_rate(){

    return HOURLY_RATE;
   }
   void set_total_working_hours(int t){
    
     total_working_hours = t;

   }
   int get_total_working_hours(){

    return total_working_hours;
   }
   void set_monthlySalary(float mSalary){
   
     monthlySalary = mSalary;

   }
   float get_monthlySalary(){

   return monthlySalary;
   }
   void calculate_salary(){

      monthlySalary = total_working_hours * HOURLY_RATE;


    cout << "Monthly salary: $" << monthlySalary << endl;

   }
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

 vector<courseType> course;



public:
  academicMemberType();  
 
 
  
  
  void addStudents();
  void dropStudents();
  void addCourses();
  void dropCourses();


};

