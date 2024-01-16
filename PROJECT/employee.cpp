#include<iostream>
#include<string>
#include<vector>
#include "Uni_Management_System_latest.h"


//  Accounts::Accounts()
//  {
//    HOURLY_RATE = 0 ;
//   total_working_hours = 0;
//   float monthlySalary;
//  }
//    void Accounts::set_rate(float r){
//    HOURLY_RATE = r;
//   }
//    float Accounts::get_rate(){
//     return HOURLY_RATE;
//    }
//    void Accounts:: set_total_working_hours(int t){
//     total_working_hours = t;
//    }
//    int Accounts:: get_total_working_hours(){
//     return total_working_hours;
//    }
//    void Accounts::set_monthlySalary(float mSalary){
//      monthlySalary = mSalary;
//    }
//    float Accounts::get_monthlySalary(){
//      return monthlySalary;
//    }

//    void Accounts:: calculate_salary(){
     
//     monthlySalary = total_working_hours * HOURLY_RATE;


//     cout << "Monthly salary: $" << monthlySalary << endl;

//     }
Accounts::Accounts(float HR,int TWH,int MS)
{
   HOURLY_RATE=HR;
   total_working_hours=TWH;
   monthlySalary=MS;
}
void Accounts::set_rate(float r)
{
  HOURLY_RATE=r;
}
void Accounts::set_total_working_hours(int t)
{
  total_working_hours=t;
}
void Accounts::set_monthlySalary(float MS)
{
  monthlySalary=MS;
}
float Accounts::get_rate()const
{
  return HOURLY_RATE;
}
float Accounts::get_monthlySalary()const
{
  return monthlySalary;
}
int Accounts::get_total_working_hours()const
{ 
  return total_working_hours;
}
 void Accounts:: calculate_salary(){
     
    monthlySalary = total_working_hours * HOURLY_RATE;


    cout << "Monthly salary: $" << monthlySalary << endl;

    }
   
  employeeType:: employeeType(){
   name = " ";
    ID = " ";
    email = " ";
    address = " ";
    designation = " ";

 }
 void employeeType:: set_data(string s , string id, string e, string add, string des){
   name = s;
    ID = id;
    email =  e;
    address = add;
    designation = des;
  }
  void employeeType:: get_data(string &s , string &id, string &e, string &add, string &des){

  }
   void employeeType :: show_payments_details(){
    
     account.calculate_salary();

   }



  facultyMemberType :: facultyMemberType(){

    }
   void  facultyMemberType :: set_marks(vector<courseType> &c, int student_no,string cId,float marks_value){
       for(int i = 0 ; i < c.size();i++)
       {
        
          if(c[i].get_courseId() == cId)

                  c[i].set_marks_value(student_no, marks_value);
        
       }
   }
   void  facultyMemberType :: set_attendance(vector<courseType> &c,int student_no,string cId,string status){
     for(int i = 0 ; i < c.size();i++)
       {
        for(int i = 0 ; i < c.size();i++)
       {
        
          if(c[i].get_courseId() == cId)
                  c[i].set_attendance(student_no, marks_value);
        
       }
       
         
        }
       }
   



 courseType::courseType()
 {
   for (int i = 0; i < courses_enrolled.size(); i++)
   {
     
     courses_enrolled[i]="";
   }
   for (int i = 0; i < course_wise_marks.size(); i++)
   {
    course_wise_marks[i]=0;
   }
   for (int i = 0; i < total_no_of_courses.size(); i++)
   {
     total_no_of_courses[i]=0;
   }
   courseId="";
 }
 void courseType::set_course_wise_attendance(vector<string> &s,int no)
 {
    for (int i = 0; i < s.size(); i++)
    {
       student.
    }
    
 }