#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

vector< string> converter( string Line, char separator)
{
 vector< string> tokens;
signed int start, end;
 string token;
start = Line.find_first_not_of(separator, 0);
do{
end = Line.find_first_of(separator, start);
if (start == Line.length() || start == end) break;
if (end >= 0) token = Line.substr(start, end - start);
else token = Line.substr(start, Line.length() - start);
tokens.push_back(token);
start = end + 1;
}
 while(end !=  string::npos);
 return tokens;
}


class courseType
{
public:
 // void courseRegister(string cName = " ", string cNo = 0 , int credits = 0);
  //void setmarks(int marks);
  //void print();
  //int getCredits();
 // string getCourseNumber();
 // string getCourseName();
 // void setmarks(string courseID );
  void setAttendance();
  //courseType(string courseName=0,float courseCredits=0,int semester_no=0);
 // friend ostream& operator<<(ostream,const courseType &);
  private:
  string courseName;
  int coursemarks;
  int courseCredits; 
  string courseGrade;
  int semester_no;
  string course_no;
  //vector<attendanceType> attendance;
};

// void courseType::courseRegister(string cName = " ",string cNo = "" , int credits = 0)
// {
//   courseName = cName;
//   if (credits<=3 && credits>=1 )
//         courseCredits = credits;
//   this->course_no=cNo;
// } 
// ostream& operator<<(ostream c,const courseType & course)
// { 
//   cout<<"Course Name: "<<course.courseName<<endl;
//   cout<<"Course Credits: "<<course.courseCredits<<endl;
//   cout<<"Course ID: "<<course.course_no<<endl;

//   return c;
// } 
// courseType::courseType(string courseName,float courseCredits,int semester_no)
// {
//   this->courseName=courseName;
//   this->coursemarks=coursemarks;
//   this->courseCredits=courseCredits;
//   this->semester_no=semester_no;
// } 
// int courseType::getCredits()
// {
//   return courseCredits;
// } 
// string courseType::getCourseName()
// {
//   return courseName;
// } 
void courseType::setAttendance()
{
  vector<string> name;
  vector<string> ROLL_NO;
  vector<string> date;
  vector<string> status; 
  string fname="attendance.txt";
  fstream file{fname};
  if(file.is_open())
  {
    string name1;
    string ROLL;
    string date1;
    string status1;
    string line;
    while(getline(file,line))
    {
      vector<string> save;
      save=converter(line,';');
        if(save.size()!=2)
            {
                continue;
            }
            try
            {
               name1=save[0];
               ROLL=save[1];
               date1=save[2];
             status1=save[3];
			      
            }
            catch(const exception& e)
            {
              //  cerr << e.what() << '\n';
                continue;
            }
    } 
           name.push_back(name1);
           ROLL_NO.push_back(ROLL);
           date.push_back(date1);
           status.push_back(status1);
    file.close();
  }
      string namee;
     cout<<"Student Name : "<<endl;
     cin>>namee;
     string rollno;
     cout<<"Roll No : "<<endl;
     cin>>rollno;
     cout<<"Enter Date : "<<endl;
     string datee;
     cin>>datee;
     string statuss;
     cout<<"Enter Status"<<endl;
     cin>>statuss;
     name.push_back(namee);
     ROLL_NO.push_back(rollno);
     date.push_back(datee);
     status.push_back(statuss);
     file.open(fname,ios::out);
     if(file.is_open())
     {

      for(int i=0;i<name.size();i++)
      {
        file<<name[i]<<";"<<ROLL_NO[i]<<";"<<date[i]<<";"<<status[i]<<endl;
      }

     }
     

      for(int i = 0 ; i < name.size() ; i++)
      {
        cout<<name[i]<<" "<<ROLL_NO[i]<< " "<< date[i] << " "<< status[i] << endl;
      }
}


 int main()
 {
    courseType A;
    A.setAttendance();
 }

