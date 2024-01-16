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
  courseType(string courseName = "", int courseCredits = 0, int no = 0, string course_no = "");
  courseType(const courseType &c);
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

courseType::courseType(const courseType& c)
{
  this->course_no=c.course_no;
  this->courseName=c.courseName;
  this->courseCredits=c.courseCredits;
  this->course_no=c.course_no;
  this->semester_no=c.semester_no;
}
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
  cout << setw(3) <<semester_no << "              ";
  cout << setw(3) << course_no << "              ";
  cout << setw(3) << courseGrade << "              "<<endl;
}
courseType::courseType(string courseName, int courseCredits, int no, string course_no)
{
  this->courseName = courseName;
  this->courseCredits = courseCredits;
  this->semester_no = no;
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
    int GetEmpIDdate;
    int temmonth;
    int GetEmpIDyear;
    i->getDateOnly(GetEmpIDdate, temmonth, GetEmpIDyear);
    if (GetEmpIDdate == d && temmonth == m && GetEmpIDyear == y)
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
  void addStdCourse(courseType c);
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

void studentType::addStdCourse(courseType c)
{
  courses.push_back(c);
}
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
  for (int i = 0; i <= courses.size(); i++)
  {

    if (courses[i].getCourseID() == courseId)
    {
      cout << courses[i].getCourseName() << " " << courses[i].getmarks() << endl;
      break;
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
  friend ostream& operator <<(ostream& co, const facultyMemberType& f);
  vector<studentType *> getFacultyStudentArray();
  string getCourseId();
  string GetEmpID();
};
vector<studentType *> facultyMemberType::getFacultyStudentArray()
{
  return students;
}
string facultyMemberType::getCourseId()
{
  return courseId;
}
ostream& operator <<(ostream& co, const facultyMemberType& f)
{
    cout<<"Name: "<<f.name<<endl;
    cout<<"ID: "<<f.ID<<endl; 
    cout<<"Email: "<<f.email<<endl;
    cout<<"Address: "<<f.address<<endl;
    cout<<"Designation: "<<f.designation<<endl;
    cout<<"Course ID: "<<f.courseId<<endl;
    return co;
}
string facultyMemberType::GetEmpID()
{
  return ID;
}
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
  void add_course(string rollNo, courseType c);
  void dropCourse(string rollNostring, string Cid);
  vector<studentType> getStudentArray() const;
  studentType& getStudent(string sid);
  int StudentsSize();
  string STDid(int no);
  string GetEmpID();
  void printAcademic()const;
};
studentType& academicMemberType::getStudent(string sid)
{
  for (int i = 0; i < students.size(); i++)
  {
    if (students[i].getSID() == sid)
    {
      return students[i];
    }
  }
  
}
void academicMemberType::printAcademic()const
{
  system("cls");
  cout<<"Name: "<<name<<endl;
  cout<<"ID: "<<ID<<endl;
  cout<<"Email: "<<email<<endl;
  cout<<"Address: "<<address<<endl;
  cout<<"Designation: "<<designation<<endl;

}
void academicMemberType::add_course(string rollNo, courseType c)
{
  for (auto i = students.begin(); i != students.end(); i++)
  {
    if (i->getSID() == rollNo)
    {
      i->addStdCourse(c);
    }
  }
}
string academicMemberType::STDid(int no)
{
  return students[no].getSID();
}
int academicMemberType::StudentsSize()
{
  return students.size();
}
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
int DisplayLoignForm();
vector< string> converter( string Line, char separator);
bool login(string Username, string Password,int input);
                                                    //Main  
int main()
{
  fstream file;
  

  academicMemberType academic("Ali", "123", "afg@gmail.com", "lahore", "academic");
  vector<facultyMemberType> faculty;
                                                   // Faculty File Handling
  file.open("Faculty.txt", ios::in);
  if (file.is_open())
  {
    string line;
    int i=0;
    while(getline(file,line))
    {
      vector<string> v = converter(line, ';');
      faculty.push_back(facultyMemberType(v[0],v[1],v[2],v[3],v[4],v[5]));
    }
  file.close();  
  }
  else
  {
      cout << "Unable to open file"<<endl;
  }
  
                                                     //Student File Handling
 file.open("Students.txt", ios::in);
  string line;

  if (file.is_open()) 
  {
        while (getline(file, line)) 
        {
            vector<string> v = converter(line, ';');

            try {
                int a = stoi(v[3]);
                academic.add_student(v[0], v[1], v[2], a);
            } catch (const invalid_argument& e) {
                cout << "Invalid argument: " << e.what() << endl;
            }
        }
        file.close();
  }
  else
  {
    cout << "Unable to open file";
  }
                                                  //Courses File Handling

  vector<courseType> c;
  file.open("Courses.txt", ios::in);
  if (file.is_open()) 
  {
    int a,b;
        while (getline(file, line)) 
        {
            vector<string> v = converter(line, ';');

            try {
                b = stoi(v[1]);
                a= stoi(v[2]);
                c.push_back(courseType(v[0], b, a, v[3]));
            } catch (const invalid_argument& e) 
            {
                continue;
            }
        }
        file.close();
  }
  else
  {
    cout << "Unable to open file";
  }
  for (int i = 0; i < academic.StudentsSize(); i++)
  {
    string SID=academic.STDid(i);
    for (int j = 0; j < c.size(); j++)
    {
      academic.add_course(SID,c[j]);
    }
  }
                     
  while (1)
  {
    int display_input=DisplayLoignForm();
    if (display_input==1)
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
        

        // system("cls");
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
            { //////code start
                                      system("cls");
            string id;
            cout<<"Enter Course ID: "<<endl;
            string courseID;
            cin>>courseID;
            for (int i = 0; i < s.size(); i++)
            {
              if (s[i].getSID()==id)
              {
                s[i].printStdMarks(courseID);
              }
            }
            }
              //// code end
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
           system("cls");
      }
      else
      {
        system("cls");
        cout<<"Login Failed"<<endl;
      } 
    }
                              //Teacher
    else if (display_input==2)
    {
      system("cls");
                         //login 
      
      string Username;
      string Password;

      cout<<"Enter Your Username: ";
      cin>>Username;
      cout<<"Enter Your Password: ";
      cin>>Password;
       
      file.open("Facultylogin.txt", ios::in);

      if (login(Username,Password,2))
      {
        int stdInput=0;
        int TeacherIndex;
        string courseID;
        cout<<"Login Successful"<<endl;

        system("cls");

        for (int i = 0; i < 5; i++)
        {
            if (Username==faculty[i].GetEmpID())
            {
              TeacherIndex=i;
              courseID=faculty[i].getCourseId();
              break;
            }  
        }

        while (1)
        {
          cout<<"1. Show Your Information "<<endl;
          cout<<"2. Mark Attendence: "<<endl;
          cout<<"3. Enter Marks: "<<endl;
          cout<<"4. Show Marks "<<endl;
          cout<<"5. Exit "<<endl;
          cin>>stdInput;

          vector<studentType*> s1=faculty[TeacherIndex].getFacultyStudentArray();

          if (stdInput==1)
          {
            system("cls");
          cout<<"Your Information:\n"<<faculty[TeacherIndex]<<endl;
          }
          else if (stdInput==2)
          {
            int d,m,y;

            cout<<"Enter Date: ";
            cin>>d>>m>>y;

            
            for (int i = 0; i < s1.size(); i++)
            {
              string stdID;
              char c;
              cout<<"Enter P for Present and A for Absent: ";
              cin>>c;
              cout<<"\n\nEnter Student ID: ";
              getline(cin,stdID);
              cin.ignore(1,'\n');
              
              s1[i]->setATTENDANCE(courseID,c,d,m,y);
            }
          }
          else if (stdInput==3)
          {
            system("cls");
            string id;
            int marks;

            cout<<"Enter Student ID: ";
            cin>>id;
            cout<<"Enter Marks: ";
            cin>>marks;

            for (int i = 0; i < s1.size(); i++)
            {
              if (s1[i]->getSID()==id)
              {
                s1[i]->setStdmarks(courseID,id,marks);
              }
            }
          }
          else if (stdInput==4)
          {
            system("cls");
            string id;

            cout<<"Enter Student ID: ";
            cin>>id;

            for (int i = 0; i < s1.size(); i++)
            {
              if (s1[i]->getSID()==id)
              {
                s1[i]->printStdMarks(courseID);
              }
            }
          }
          else if (stdInput==5)
          {
            system("cls");
            break;
          }
          system("cls");
        }
      }
    }
    else if (display_input==3)
    {
      system("cls");
                                    //login 
      
      string Username;
      string Password;

      cout<<"Enter Your Username: ";
      cin>>Username;
      cout<<"Enter Your Password: ";
      cin>>Password;

      if (Username=="123" && Password=="admin")
      {
        cout<<"Login Successful"<<endl;

        system("cls");

        while (1)
        {
          system("cls");
          int stdInput;
          cout<<"1. Show Your Information "<<endl;
          cout<<"2. Assign Students: "<<endl;
          cout<<"3. Drop Students: "<<endl;
          cout<<"4. Add Students: "<<endl;
          cout<<"5. Exit "<<endl;
          cin>>stdInput;

          if (stdInput==1)
          {
            academic.printAcademic();
          }
          else if (stdInput==2)
          {
            system("cls");
              string id;
              string Tid;
              string courseID;
              int tIndex;

              
              cout<<"Enter Teacher ID: ";
              cin>>Tid;
              cout<<"Enter Course ID: ";
              cin>>courseID;

              for (int i = 0; i < faculty.size(); i++)
              {
                  if (faculty[i].GetEmpID()==Tid && faculty[i].getCourseId()==courseID)
                  {
                    tIndex=i;
                     while (1)
                     {  
                      int input7;
                      cout<<"\n\nEnter Student ID: ";
                      cin>>id;
                      faculty[i].addstudentsFACULTY(&academic.getStudent(id));

                      cout<<"Enter 1 to add more students:\nEnter 2 for exit:  ";
                      cin>>input7;

                      vector<studentType *>students=faculty[tIndex].getFacultyStudentArray();
                    
                       string c=courseID+".txt";
                       file.open(c,ios::out);
                       if(file.is_open())
                       {
                             for (int i = 0; i < students.size(); i++)
                            {
                              
                              file<<students[i]->getSID()<<";"<<endl;
                              

                            } 
                             }
                       else
                       {
                        cout<<"File not open"<<endl;
                       }
                      file.close();

                      system("cls");
                      if (input7==2)
                      {
                        break;
                      }
                    }
                    break;
                } 
              }
          }
          else if (stdInput==3)
          {
            system("cls");
              string id;

              
              cout<<"Enter Student ID: ";
              cin>>id;

              vector<studentType> student;
              student=academic.getStudentArray();

              for(int i=0;i<student.size();i++)
              {
                if (student[i].getSID()==id)
                {
                  academic.drop_student(id);
                  break;
                }
              }

          }
          else if (stdInput==4)
          {
            system("cls");
            string fname,lname,sID;
            int semNo;
            cout<<"Enter Student First Name: ";
            cin>>fname;
            cout<<"Enter Student Last Name: ";
            cin>>lname;
            cout<<"Enter Student ID: ";
            cin>>sID;
            cout<<"Enter Student Semester No: ";
            cin>>semNo;

            academic.add_student(fname,lname,sID,semNo);
            cout<<"\n\nStudent Successfully Added\n\n";
            system("cls");
          }
          else if (stdInput==5)
          {
            system("cls");
            break;
          }
        }
      }
    }

    else if (display_input==4)
    {
      cout<<"\n\n\t\t\tAllah Hafiz.\n\n"<<endl;
      cout<<"\n\nCreated By Team Lazy Progmmers.\n\n";
      break;
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

int DisplayLoignForm()
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
      string GetEmpID1,GetEmpID2;
      fstream file;
      string line;
      string file_decision;

      if (input==1)
          file_decision="student";
      else if (input==2)
          file_decision="Faculty";
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
        GetEmpID1=save[0];
        GetEmpID2=save[1];  
        if (GetEmpID1==Username && GetEmpID2==Password)
        {
          return true;
        }
      } 
    file.close();

    return false;
}