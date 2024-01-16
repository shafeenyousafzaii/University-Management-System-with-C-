#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
const int MAX_NO_OF_STUDENTS = 10;
class dateType
{
  int date;
  int month;
  int year;

public:
  dateType(int d = 1, int m = 1, int y = 2000); // KAshif
  void setDate(int d, int m, int y);
  void getDate(int &d, int &m, int &y) const;
};
enum status
{
  present,
  absent,
  late
}; // Kashif
class attendanceType
{
  dateType date;  // KAshif
  status _status; // KAshif

public:
  attendanceType(int d = 1, int m = 1, int y = 2000, status s = present); // KAshif
  void setStatusOnly(char s);
  void setDateOnly(int d, int m, int y); // KAshif
  void getStatus(int &d, int &m, int &y, char &s) const;
};



class employeeType
{
protected:
  string name;
  string ID;
  string email;
  string address;
  string designation;
   

public:
  employeeType();
  void set_data(string s, string id, string e, string add, string des, int NOC);
  void get_data(string &s, string &id, string &e, string &add, string &des);

  void show_payments_details();
};

class facultyMemberType : public employeeType
{
  string courseId;

  vector<courseType> courses;

public:
  facultyMemberType();
  void set_marks(vector<courseType> &c, int student_no, string cId, float marks_value);
  void set_attendance(vector<courseType> &c, int student_no, string cId, string status);
};
class personType
{
public:
  void print() const;
  void setName(string first, string last);
  string getFirstName() const;
  string getLastName() const;
  personType(string first = "", string last = "");

private:
  string firstName;
  string lastName;
};
//--------------------------------------------
class courseType
{
public:
  void setCourseInfo(string cName, string cNo, int credits);
  void setmarks(int marks);
  void print();
  int getCredits();
  string getCourseNumber();
  string getCourseName();
  void enrollStudent(studentType* student);
    void setTeacher(facultyMemberType* teacher) ;
    void setMarks(studentType* student, float marks);
  friend void setmarks(string courseID , string ROLLNOO);
  // void getmark
  courseType(string cName = "", string cNo = "", int credits = 0);

private:
  // courseCredits    =    credits;
  string courseName;
  int coursemarks;
  // string courseNo;
  int courseCredits; //
  string coursegrade;
  int semester_no;
  facultyMemberType* teacher;
  studentType *student[];
};
// class semesterType
// {
//   private:
//   courseType c[6];
//   float SGPA;
//   string grade;
//   public :
//   semesterType();
//   void setSGPA();
//   void setgrade();
// };
//-------------------------------------------------------------------------------------------------------------------
class studentType : public personType
{
public:
  studentType(string x="",string y="");
  void setInfo(string fname, string lName, int ID);
  void print();
  void addsemester();
    friend void setmarks(string courseID , string ROLLNOO);


private:
  void sortCourses();
  int sId;
  static int semesterNO;
  static int size;
courseType *c;
};

//----------------------------------------------------------------------------------------------------------------------
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
void dateType::getDate(int &d, int &m , int &y)const
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

courseType::courseType(string cName, string cNo, int credits)
{
  courseName = cName;
  courseCredits = credits;
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
  c= new courseType[4];
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
