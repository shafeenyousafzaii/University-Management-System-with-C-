#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;
class studentType;
class dateType;
class attendanceType;
class personType;
class facultyMemberType;
class courseType;

                                            //Final  date type class
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
dateType::dateType(int d, int m, int y)
{
  setDate(d,m,y);
}
void dateType::setDate(int d, int m, int y)
{
  if (d>=1 && d<=31 && m>=1 && m<=12 && y>=2000 )
  {
    date = d;
    month = m;
    year = y;
  }
  else 
    cout<<"Invalid Date!"<<endl;
}
void dateType::getDate(int &d, int &m, int &y) const
{
  d = date;
  m = month;
  y = year;
}
void dateType::printDate() const
{
  cout << date << " / " << month << " / " << year << setw(5) << right;
}

                                                            //Final ss Class attendanceType

enum status{present,absent,late};//Enum
class attendanceType
{
  dateType date;
  status _status;

public:
  attendanceType(int d = 1, int m = 1, int y = 2000, char s = present);
  void setStatusOnly(char s);
  char getStatusOnly() const;
  void setDateOnly(int d, int m, int y);
  void getDateOnly(int &d, int &m, int &y) const;
  void printDate() const;
};
char attendanceType::getStatusOnly() const
{

  if (_status == present)
    return 'P';
  else if (_status == absent)
    return 'A';
  else if (_status == late)
    return 'L';
}
void attendanceType::printDate() const
{
  date.printDate();

  cout << "  Status : " << this->getStatusOnly() << endl;
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

attendanceType::attendanceType(int d, int m, int y, char s) : date(d, m, y)
{
  setStatusOnly(s);
}

void attendanceType::getDateOnly(int &d, int &m, int &y) const
{
  date.getDate(d, m, y);
}

                                                      // Final Person Type
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
                                              // Final Course Type
class courseType
{
public:
  void setCourseInfo(string cName, int coursemarks, string cNo, int credits);
  float getmarks();
  string getGrade();
  void printCourses();
  int getCredits();
  string getCourseNumber();
  string getCourseName();
  void setCoursemarks(float marks);
  void setAttendance(string courseID, char status, int date, int month, int year);
  void printAttendence(int d, int m, int y);
  courseType(string courseName = "", int courseCredits = 0, int semester_no = 1, string course_no = "");
  string getCourseID();

private:
  string courseName;
  int coursemarks;
  int courseCredits;
  string courseGrade;
  int semester_no;
  string course_no;
  vector<attendanceType> attendance;
};

string courseType::getGrade()
{
  return courseGrade;
}
float courseType::getmarks()
{
  return coursemarks;
}
void courseType::setCoursemarks(float marks)
{
  if (marks >= 0 && marks <= 100)
  {
    coursemarks = marks;
  }
}
string courseType::getCourseID()
{
  return course_no;
}
void courseType::setCourseInfo(string cName = " ", int coursemarks = 0, string cNo = 0, int credits = 0)
{
  courseName = cName;
  courseCredits = credits;
  this->coursemarks = coursemarks;
  course_no = cNo;
  courseCredits = credits;
}
void courseType::printCourses()
{
  cout << left;
  cout << setw(15) << courseName;
  cout << right;
  cout << setw(3) << courseCredits << "              ";
  cout << setw(3) << coursemarks << "              ";
  cout << setw(3) << courseGrade << "              ";
}
courseType::courseType(string courseName, int courseCredits, int semester_no, string course_no)
{
  this->courseName = courseName;
  this->courseCredits = courseCredits;
  this->semester_no = semester_no;
  this->course_no = course_no;
}

int courseType::getCredits()
{
  return courseCredits;
}
string courseType::getCourseName()
{
  return courseName;
}
void courseType::setAttendance(string courseID, char status, int d, int m, int y)
{
  attendance.push_back(attendanceType(d, m, y, status));
}
void courseType::printAttendence(int d, int m, int y)
{
  for (auto i = attendance.begin(); i != attendance.end(); i++)
  {
    int tempdate;
    int temmonth;
    int tempyear;
    i->getDateOnly(tempdate, temmonth, tempyear);
    if (tempdate == d && temmonth == m && tempyear == y)
    {
      i->printDate();
    }
  }
}
                                        // Final student Type
class studentType : public personType
{
public:
  studentType(string x = "", string y = "",string StdID="", int sNo = 1);
  void setInfo(string fname, string lName, int ID);
  void print();
  string getSID();
  void setStdmarks(string courseID, string SIDO, float marks);
  void printStdMarks(string courseId);
  void addStdCourse(string CName, int Ccredits, int SemNo, string CNo);
  void removeStdCourse(string courseid);
  void setATTENDANCE(string courseID, char status, int d, int m, int y);
  void printAttendance(int d, int m, int y, string courseID);
  float CalStdCGPA();
  void printStdCourses();

private:
  string SID;
  int semesterNO;
  vector<courseType> courses;
  float CGPA;
};

void studentType::printStdCourses()
{
    for (int i = 0; i < courses.size(); i++)
    {
        cout<<"\nCourse"<<i+1<<" "<<endl;
        courses[i].printCourses();
    }
}
float studentType::CalStdCGPA()
{
  float sum = 0;
  int totalCredits=0;

  for (auto i = 0; i < courses.size() ; i++)
  {
    totalCredits+=courses[i].getCredits();
    if (courses[i].getGrade()=="A" || courses[i].getGrade()=="A+")
    {
      sum += courses[i].getCredits() * 4;
      continue;
    }
    else if (courses[i].getGrade()=="B")
    {
      sum += courses[i].getCredits() * 3;
      continue;
    }
    else if (courses[i].getGrade()=="C")
    {
      sum += courses[i].getCredits() * 2;
      continue;
    }
    else if (courses[i].getGrade()=="D")
    {
      sum += courses[i].getCredits() * 1;
      continue;
    }
    else if (courses[i].getGrade()=="F")
      continue;
  }

  CGPA=sum / totalCredits;
  return CGPA;
}
void studentType::removeStdCourse(string courseid)
{
  for (auto i = courses.begin(); i != courses.end(); i++)
  {
    if (i->getCourseID() == courseid)
    {
      courses.erase(i);
    }
  }
}
void studentType::printStdMarks(string courseId)
{
  for (auto i = courses.begin(); i != courses.end(); i++)
  {
    if (i->getCourseID() == courseId)
    {
      cout << i->getCourseName() << " " << i->getmarks() << endl;
    }
  }
}
void studentType::addStdCourse(string CName, int Ccredits, int SemNo, string CNo)
{
  courses.push_back(courseType(CName, Ccredits, SemNo, CNo));
}
void studentType::setStdmarks(string courseID, string SIDO, float marks)
{
  for (auto i = courses.begin(); i != courses.end(); i++)
  {
    if (i->getCourseID() == courseID && SID == SIDO)
    {
      i->setCoursemarks(marks);
    }
  }
}

string studentType::getSID()
{
  return SID;
}

void studentType::setInfo(string fName, string lName, int ID)
{
  personType::setName(fName, lName);
  SID = ID;
}

studentType::studentType(string x, string y,string StdID, int sNo) : personType(x, y)
{
  SID = StdID;
  if (semesterNO >= 1)
  {
    semesterNO = sNo;
  }
}
void studentType::print()
{

  cout << "Student Name: " << getFirstName() << "    " << getLastName() << endl;
  cout << "Student    ID:    " << SID << endl;
  cout << "Student Semester No:    " << semesterNO << endl;
  cout << endl;
  cout << endl;
  cout << setw(4) << "***" << endl;
  cout << fixed << showpoint << setprecision(2);
  cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"
       << "-*-*-*-*-" << endl
       << endl;
}
void studentType::setATTENDANCE(string courseID, char status, int d, int m, int y)
{
  for (auto i = courses.begin(); i != courses.end(); i++)
  {
    if (i->getCourseID() == courseID)
    {
      i->setAttendance(courseID, status, d, m, y);
    }
  }
}
void studentType::printAttendance(int d, int m, int y, string courseID)
{
  for (auto i = courses.begin(); i != courses.end(); i++)
  {
    if (i->getCourseID() == courseID)
    {
      i->printAttendence(d, m, y);
    }
  }
}
// final employeeType
class employeeType
{
protected:
  string name;
  string ID;
  string email;
  string address;
  string designation;

public:
  employeeType(string name = " ", string id = " ", string email = " ", string address = " ", string designation = "");
  void set_data(string s, string id, string e, string add, string des);
  void get_data(string &s, string &id, string &e, string &add, string &des);
};
employeeType::employeeType(string name, string id, string email, string address, string designation)
{
  this->name = name;
  this->ID = id;
  this->email = email;
  this->address = address;
  this->designation = designation;
}
void employeeType::set_data(string name, string id, string email, string address, string designation)
{
  this->name = name;
  this->ID = id;
  this->email = email;
  this->address = address;
  this->designation = designation;
}
void employeeType::get_data(string &s, string &id, string &e, string &add, string &des)
{
  s = name;
  id = ID;
  e = email;
  add = address;
  des = designation;
}
// final faculty Member Type
class facultyMemberType : public employeeType
{
  string courseId;
  vector<studentType *> students;

public:
  facultyMemberType(string name = " ", string id = " ", string email = " ", string address = " ", string designation = " ", string courseId = " ");
  void addstudentsFACULTY(studentType *s);
  void set_marks(string SID, string courseId, float marks);
  void show_marks(string SID, string courseid) const;
  void set_attendance(int student_no, string cId, char status, int d, int m, int y);
  void showattendance(int d, int m, int y, string courseID) const;
};

void facultyMemberType::show_marks(string SID, string courseid) const
{
  for (auto i = students.begin(); i != students.end(); i++)
  {
    if ((*i)->getSID() == SID)
    {
      (*i)->printStdMarks(courseid);
    }
  }
}
facultyMemberType::facultyMemberType(string n, string id, string email, string address, string desig, string cId) : employeeType(n, id, email, address, desig)
{
  courseId = cId;
}
void facultyMemberType::set_marks(string SID, string courseId, float marks)
{
  for (auto i = students.begin(); i != students.end(); i++)
  {
    if ((*i)->getSID() == SID)
    {
      (*i)->setStdmarks(courseId, SID, marks);
    }
  }
}

void facultyMemberType::addstudentsFACULTY(studentType *s)
{
  students.push_back(s);
}
void facultyMemberType::set_attendance(int student_no, string cId, char status, int d, int m, int y)
{
  for (auto i = students.begin(); i != students.end(); i++)
  {
    if ((*i)->getSID() == cId)
    {
      (*i)->setATTENDANCE(cId, status, d, m, y);
    }
  }
}
void facultyMemberType::showattendance(int d, int m, int y, string courseID) const
{
  for (auto i = students.begin(); i != students.end(); i++)
  {
    (*i)->printAttendance(d, m, y, courseID);
  }
}
// final academic class
class academicMemberType : public employeeType
{
  vector<studentType> students;

public:
  academicMemberType(string s="", string id="", string e="", string add="", string des="");
  void add_student(string fname, string lname, string sID,int semesterNO);
  void drop_student(string sid);
  void add_course(string rollNo, int semNo, string Cname, string Cid, int Ccredit);
  void dropCourse(string rollNostring, string Cid);
  vector<studentType> getStudentArray() const;
};
academicMemberType::academicMemberType(string s, string id, string e, string add, string des) : employeeType(s, id, e, add, des)
{
}
vector<studentType> academicMemberType::getStudentArray() const
{
  return students;
}
void academicMemberType::dropCourse(string rollNo, string Cid)
{
  for (auto i = students.begin(); i != students.end(); i++)
  {
    if (i->getSID() == rollNo)
    {
      i->removeStdCourse(Cid);
    }
  }
}
void academicMemberType::add_course(string rollNo, int semNo, string Cname, string Cid, int Ccredit)
{
  for (auto i = students.begin(); i != students.end(); i++)
  {
    if (i->getSID() == rollNo)
    {
      i->addStdCourse(Cname, Ccredit, semNo, Cid);
    }
  }
}
void academicMemberType::add_student(string fname, string lname, string sID,int semesterNO)
{
  students.push_back(studentType(fname, lname, sID,semesterNO));
}
void academicMemberType::drop_student(string sid)
{
  for (auto i = students.begin(); i != students.end(); i++)
  {
    if (i->getSID() == sid)
      students.erase(i);
  }
}

//Function Declerations
int displayLoginForm();
vector< string> converter( string Line, char separator);
bool login(string Username, string Password,int input);

int main()
{
  academicMemberType academic("Ali", "123", "afg@gmail.com", "lahore", "academic");
  facultyMemberType faculty;
  fstream file;

  file.open("Students.txt", ios::in);
  string line;

  if (file.is_open())
  {
    while (getline(file, line))
    {
      vector<string> v = converter(line, ';');
      int a;

      a=stoi(v[3]);
      academic.add_student(v[0],v[1],v[2],a);
      
    }
    file.close();
  }
  else
  {
    cout << "Unable to open file";
  }
  
  while (1)
  {
    if (displayLoginForm()==1)
    {
      system("cls");
      
      //login 
      string Username;
      string Password;

      cout<<"Enter Your Username: ";
      cin>>Username;
      cout<<"Enter Your Password: ";
      cin>>Password;

      if (login(Username,Password,1))
      {
        int stdInput=0;
        cout<<"Login Successful"<<endl;

        system("cls");
          while (1)
          {
            cout<<"1. Show Your Information "<<endl;
            cout<<"2. Show CGPA "<<endl;
            cout<<"3. Show Attendance "<<endl;
            cout<<"4. Show Marks "<<endl;
            cout<<"5. Show Courses "<<endl;
            cout<<"6. Exit "<<endl;
            cin>>stdInput;
            vector<studentType> s;
            int id_index;

            s=academic.getStudentArray();
            for (int i = 0; i < s.size(); i++)
            {
                if (Username==s[i].getSID())
                {
                    id_index=i;
                }
            }

            if (stdInput==1)
            {
              s[id_index].print();
            }
            else if (stdInput==2)
            {
              float cgpa=s[id_index].CalStdCGPA();
              cout<<"Your CGPA is: "<<cgpa<<endl;
            }
            else if (stdInput==3)
            {
              int d,m,y;
              string courseID;
              cout<<"Enter Date: ";
              cin>>d>>m>>y;
              cout<<"Enter Course ID: ";
              cin>>courseID;
              
              s[id_index].printAttendance(d,m,y,courseID);
            }
            else if (stdInput==4)
            {
              string courseID;
              cout<<"Enter Course ID: ";
              cin>>courseID;

              s[id_index].printStdMarks(courseID);
            }
            else if (stdInput==5)
            {
              s[id_index].printStdCourses();
            }
            else if (stdInput==6)
            {
              s.clear();
              system("cls");
              break;
            }

          }
      }
      else
      {
        cout<<"Login Failed"<<endl;
      } 
      return 0;
    }

  //yha tk krliya
    else if (displayLoginForm()==2)
    {
      system("cls");
    }
    else if (displayLoginForm()==3)
    {
      system("cls");
    }
    else if (displayLoginForm()==4)
    {
      system("cls");
    }
    else
    {
      cout<<"Invalid Input"<<endl;
    }
  }
  
    

    return 0;
}


vector< string> converter( string Line, char separator)
{
 vector< string> tokens;
 signed int start, end;
 string token;
 start = Line.find_first_not_of(separator, 0);

do{

end = Line.find_first_of(separator, start);

if (start == Line.length() || start == end) 
    break;

if (end >= 0) 
    token = Line.substr(start, end - start);

else 
    token = Line.substr(start, Line.length() - start);


tokens.push_back(token);
start = end + 1;

}while(end !=  string::npos);
 
return tokens;
}

int displayLoginForm()
{
    int input;
    string title = "LOGIN FORM";
    string options[] = {"1. Student", "2. Teacher", "3. Academic Member", "4. Exit"};

    int screenWidth = 200;  
    int screenHeight = 24; 

    int formWidth = title.length() + 4;
    int formHeight = sizeof(options) / sizeof(options[0]);

    int xPos = (screenWidth - formWidth) / 2;
    int yPos = (screenHeight - formHeight) / 2;

    for (int i = 0; i < yPos; i++)
        cout << endl;

    for (int i = 0; i < xPos; i++)
        cout << " ";

    cout << "======================" << endl;

    for (int i = 0; i < xPos; i++)
        cout << " ";

    cout << "     " << title << endl;

    for (int i = 0; i < xPos; i++)
        cout << " ";

    cout << "======================" << endl;

    for (int i = 0; i < formHeight; i++)
    {
        for (int j = 0; j < xPos; j++)
            cout << " ";

        cout << options[i] << endl;
    }

    cin >> input;
    return input;
}

bool login(string Username, string Password,int input)
{
      string temp1,temp2;
      fstream file;
      string line;
      string file_decision;

      if (input==1)
          file_decision="student";
      else if (input==2)
          file_decision="teacher";
      else if (input==3)
          file_decision="academic";

      file.open(file_decision+"login.txt",ios::in);

      while(getline(file,line))
      {
        vector<string> save;
        save=converter(line,';');
        if(save.size()!=2)
        {
                continue;
        }
        temp1=save[0];
        temp2=save[1];  
        if (temp1==Username && temp2==Password)
        {
          return true;
        }
      } 
    file.close();

    return false;
}