#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class studentType;
class dateType;
class attendanceType;
class personType;
class facultyMemberType;
class courseType;
// class studentType

                                                            //date type class 
class dateType
{
  int date;
  int month;  
  int year;

public:
  dateType(int d = 1, int m = 1, int y = 2000); 
  void setDate(int d, int m, int y);
  void getDate(int &d, int &m, int &y) const; 
  void printDate() const;
};
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
  d=date;
  m=month;
  y=year;
}
void dateType::printDate() const
{
  cout<<date<<" / "<<month<<" / "<<year<<setw(5)<<right<<endl;
}

                                                  // Class attendanceType
enum status {present,absent,late};
class attendanceType
{
  dateType date;  
  status _status; 

public:
  attendanceType(int d = 1, int m = 1, int y = 2000, status s = present);
  void setStatusOnly(char s);
  void setDateOnly(int d, int m, int y); 
  void getStatus(int &d, int &m, int &y, char &s) const;
};

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

attendanceType::attendanceType(int d, int m, int y, status s) : date(d, m, y)
{
    this->_status = s;
}

void attendanceType::getStatus(int &d, int &m, int &y, char &s) const
{
    int date;
    int month;
    int year;
    this->date.getDate(date, month, year);
    d = date;
    m = month;
    y = year;

    // char s;
    if (_status == present)
        s = 'P';
    else if (_status == absent)
        s = 'A';
    else if (_status == late)
        s = 'L';
    cout << s << endl;
}


                                                      //Person Type
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
                                                        //Course Type
class courseType
{
public:
  void setCourseInfo(string cName ,int coursemarks, string cNo  , int credits );
  void setmarks(int marks);
  void print();
  int getCredits();
  string getCourseNumber();
  string getCourseName();
  void enrollStudent(studentType* student);
  void setTeacher(facultyMemberType* teacher) ;
  void setMarks(studentType* student, float marks);
 void setmarks(string courseID , string ROLLNOO);
 void setAttendance(string courseID , char status);
  courseType(string courseName="",int coursemarks=0,float courseCredits=0,string coursegrade=" ",int semester_no = 0);

private:
  string courseName;
  int coursemarks;
  float courseCredits; 
  string courseGrade;
  int semester_no;
  string course_no;
  static int std_count;
  // studentType *students;
  attendanceType *attendance;
};

void courseType::setCourseInfo(string cName = " ",int coursemarks = 0 , string cNo = 0 , int credits = 0)
{
  courseName = cName;
  courseCredits = credits;
  this->coursemarks=coursemarks;
  course_no=cNo;
  courseCredits=credits;
} 
void courseType::print()
{
  cout << left;
  cout << setw(15) << courseName;
  cout << right;
  cout << setw(3) << courseCredits << "              ";
} 
courseType::courseType(string courseName,int coursemarks,float courseCredits,string coursegrade,int semester_no)
{
  this->courseName=courseName;
  this->coursemarks=coursemarks;
  this->courseCredits=courseCredits;
  this->courseGrade=coursegrade;
  this->semester_no=semester_no;
} 
int courseType::getCredits()
{
  return courseCredits;
} 
string courseType::getCourseName()
{
  return courseName;

} 
void courseType::setAttendance(string courseID , char status)
{
  
    int i;
    for(i=0;i<std_count;i++)
    {
      if(this->course_no==courseID)
      {
        attendance[i].setDateOnly(1,1,2000);
        attendance[i].setStatusOnly(status);
      }
    }

//   int i;
//   for(i=0;i<std_count;i++)
//   {
//     if(students[i].getRollNo()==ROLLNOO)
//     {
//       attendance[i].setDateOnly(1,1,2000);
//       attendance[i].setStatusOnly('P');
//     }
//   }
// }
}
                                              //student Type
class studentType : public personType
{
public:
 friend class facultyMemberType;
  studentType(string x="",string y="");
  void setInfo(string fname, string lName, int ID);
  void print();
  void addsemester();
  string getRollNo();
  friend void setmarks(string courseID , string ROLLNOO);

private:
  void sortCourses();
  int sId;
  string ROLL_NO;
  static int semesterNO;
  static int size;
  courseType *c;
};
string studentType::getRollNo()
{
  return ROLL_NO;
}

void studentType::setInfo(string fName, string lName, int ID)
{
  // int i;
  setName(fName, lName);
  sId = ID;

}
int   studentType::semesterNO=1;
int studentType::size=1;
studentType::studentType(string x,string y):personType(x,y)
{
  sId = 0;
  c=new courseType[size];
}


void studentType::print()
{
  // int i;
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

                                                    // employeeType
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
  void set_data(string s, string id, string e, string add, string des);
  void get_data(string &s, string &id, string &e, string &add, string &des);

  void show_payments_details();
};
employeeType::employeeType()
{
  name="";
  ID="";
  email="";
  address="";
  designation="";
}
void employeeType::set_data(string name , string id , string email , string address , string designation)
{
   this->name=name;
   this->ID=id;
   this->email=email;
   this->address=address;
   this->designation=designation;
}
void employeeType::get_data(string &s, string &id, string &e, string &add, string &des)
{
 name=s;
  ID=id;
  email=e;
  address=add;
  designation=des;

}
                                                    //faculty Member Type
class facultyMemberType : public employeeType
{
  string courseId;
  studentType *students;
  static int size;
public:
  facultyMemberType();
  void set_marks(int student_no, string cId, float marks_value);
  void set_attendance( int student_no, string cId, string status);
};
int facultyMemberType::size=1;


facultyMemberType::facultyMemberType()
{
  students = new studentType[size];
  courseId = " ";
}

void facultyMemberType::set_marks(int student_no, string cId, float marks_value)
{
  if(cId==courseId)
  {
    int i;
    for(i=0;i<size;i++)
    {
      if(students[i].sId==student_no)
      {
        students[i].c->setMarks(&students[i],marks_value);
        break;
      }
    }
  }
  // int i;
  // for (i = 0; i < size; i++)
  // {
  //   if (students[i].sId == student_no)
  //   {
  //     students[i].c->setMarks(&students[i], marks_value);
  //     break;
  //   }
  // }
}



                                                    //academic Member Type

class academicMemberType : public employeeType
{
   studentType *students;
   
public:
    academicMemberType(){
    }

  
     void set_gpa();
  
};



int main()
{
  studentType s[10];
  facultyMemberType f[10];
  academicMemberType a[10];
  for (int i = 0; i < 10; i++)
  {
    string fname,Lname;
    int ID;
    cout<<"Student enter Your First Name : "<<endl;
    cin>>fname;
    cout<<"Student enter your Last Name  : "<<endl;
    cin>>Lname;
    cout<<"Student enter your ID         :"<<endl;
     s[i].setInfo(fname,Lname,ID);
     s[i].addsemester();
  }
  for (int i = 0; i < 10; i++)
  {
    string fname,Lname;
    int ID;
    cout<<"Faculty Member enter Your First Name : "<<endl;
    cin>>fname;
    cout<<"Faculty Member enter your Last Name  : "<<endl;
    cin>>Lname;
    cout<<"Faculty Member enter your ID         :"<<endl;
     f[i].set_data(fname,Lname,ID);
  }
  
  
}