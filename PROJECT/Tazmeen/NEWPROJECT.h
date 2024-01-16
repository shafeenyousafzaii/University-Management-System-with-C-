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
  void getDate() const;
  // void getDate(int &d, int &m, int &y) const; //shafeen
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
  // void getStatus(int &d, int &m, int &y, char &s) const; //shafeen
    void getStatus() const;

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

  // vector<courseType> courses;

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
  void setCourseInfo(string cName = " ", string cNo = 0 , int credits = 0);
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
  courseType(string courseName="",int coursemarks=0,float courseCredits=0,string coursegrade,int semester_no);

private:
  // courseCredits    =    credits;
  string courseName;
  int coursemarks;
  // string courseNo;
  float courseCredits; //
  string coursegrade;
  int semester_no;
  facultyMemberType* teacher;
  // studentType *student[];
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
// int *c;
courseType *c;
};

//----------------------------------------------------------------------------------------------------------------------
