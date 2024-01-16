#include <iostream>
#include <string>
#include <iomanip>
#include "NEWPROJECT.h"
using namespace std;
dateType::dateType(int d,int m,int y)
{
  date=d;
  month=m;
  year=y;
}
void dateType::setDate(int d , int m , int y)
{
  date=d;
  month=m;
  year=y;
}
// void dateType::getDate(int &d, int &m , int &y)const
// shafeen
void dateType::getDate()const
{
  cout<<date<<" / "<<month<<" / "<<year<<setw(5)<<right<<endl;
}
// Class attendanceType
attendanceType::attendanceType(int d, int m, int y, status s) : date(d, m, y)
{
    this->_status = s;
}
void attendanceType::setStatusOnly(char s)
{
    if (s == 'P' || s == 'p')
        _status = present;
    else if (s == 'A' || s == 'a')
        _status = absent;
    else if (s == 'L' || s == 'l')
        _status = late;
}
void attendanceType::setDateOnly(int d, int m, int y)
{
    date.setDate(d, m, y);
}
//shafeen

// void attendanceType::getStatus(int &d, int &m, int &y, char &s) const
void attendanceType::getStatus() const

{
    // int date;
    // int month;
    // int year;
    this->date.getDate();

    // d = date;
    // m = month;
    // s = year;
    char s;
    if (_status == present)
        s = 'P';
    else if (_status == absent)
        s = 'A';
    else if (_status == late)
        s = 'L';
    cout << s << endl;
}

employeeType::employeeType()
{
  name="";
  ID="";
  email="";
  address="";
  designation="";
}
void employeeType::set_data(string name , string id , string email , string address , string designation,int NOC)
{
   this->name=name;
   this->ID=id;
   this->email=email;
   this->address=address;
   this->designation=designation;
}
void employeeType::get_data(string &s, string &id, string &e, string &add, string &des)
{
  cout<<"Name          : "<<name<<endl;
  cout<<"ID            : "<<ID<<endl;
  cout<<"Email         : "<<email<<endl;
  cout<<"Address       : "<<address<<endl;
  cout<<"Designation   : "<<designation<<endl;
}
void personType::print() const
{
  cout << firstName << "    " << lastName;
}
void personType::setName(string first, string last)
{
  firstName = first;
  lastName = last;
}
string personType::getFirstName() const
{
  return firstName;
}
string personType::getLastName() const
{
  return lastName;
}

personType::personType(string first, string last)
{
  firstName = first;
  lastName = last;
}
void courseType::setCourseInfo(string cName, string cNo, int credits)
{
  courseName = cName;
  courseCredits = credits;
} //

void courseType::print()
{
  cout << left;
  cout << setw(15) << courseName;
  cout << right;
  cout << setw(3) << courseCredits << "              ";
} //

courseType::courseType(string courseName,int coursemarks,float courseCredits,string coursegrade,int semester_no)
{
  this->courseName=courseName;
  this->coursemarks=coursemarks;
  this->courseCredits=courseCredits;
  this->coursegrade=coursegrade;
  this->semester_no=semester_no;
} //
int courseType::getCredits()
{
  return courseCredits;
} //
string courseType::getCourseName()
{
  return courseName;
} //

void studentType::setInfo(string fName, string lName, int ID)
{
  int i;
  setName(fName, lName);
  sId = ID;

}
int   studentType::semesterNO=1;
int studentType::size=1;
studentType::studentType(string x,string y):personType(x,y)
{
  sId = 0;
  // c= new courseType[size];
  // c=new int[size];s
  c=new courseType[size];
}


void studentType::print()
{
  int i;
  cout << "Student Name: " << getFirstName() << "    " << getLastName() << endl;
  cout << "Student    ID:    " << sId << endl;
  cout << endl;
  cout << left;
  cout << "Course    No" << setw(15) << "         Course    Name" << setw(8) << "Credits" << setw(6) << "Grade" << endl;
  cout << right;
  
  
  cout << endl;
  cout << setw(4) << "***" << endl;
  cout << fixed << showpoint << setprecision(2);
  cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"
       << "-*-*-*-*-" << endl
       << endl;
}
