#include <iostream>
#include "Uni_Management_System.h"
#include<vector>

using namespace std;

// Date Type Class
dateType::dateType(int d, int m, int y)
{
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
void dateType::getDate(int &d, int &m, int &y) const
{
    d = date;
    m = month;
    y = year;
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
void attendanceType::getStatus(int &d, int &m, int &y, char &s) const
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

//Student Type Class Definition
  studentType::studentType(string s , string id, string e, string f_name, string add, int no)
  {
    set_data(s,id,e,f_name,add,no);
  }
  void studentType::set_data(string s , string id, string e, string f_name, string add, int no)
  {
    name=s;
    ID=id;
    email=e;
    father_name=f_name;
    address=add;
    semester_no=no;
  }
  void studentType::get_data(string &s , string &id, string &e, string &f_name, string &add, int &no)const
  {
    s=name;
    id=ID;
    e=email;
    f_name=father_name;
    add=address;
    no=semester_no;
  }
  void studentType::show_attendance_details(int d,int m,int y)
  {
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
  void studentType::set_attendance_status( int no, char status)
  {
    attendance[no].setStatusOnly(status);
  }
  void studentType::set_attendance_date( int no, int d, int m, int y)
  {
    attendance[no].setDateOnly(d,m,y);
  }
  void studentType::set_cgpa(float c)
  {
    if (cgpa>=1 && cgpa<=4)
    {
        cgpa=c;
    }
    else
        cout<<"Invalid CGPA."<<endl;
  }
  float studentType::get_cgpa()
  {
    return cgpa;
  }