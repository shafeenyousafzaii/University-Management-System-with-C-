#include<iostream>
#include<string>
#include<vector>
#include<Uni_Management_System_kashif.h>
using namespace std;
Accounts::Accounts()// shafeen
{
    HOURLY_RATE=0;
    total_working_hours=0;
    monthlySalary=0;
}
void Accounts::set_rate(float r) // shafeen
{
    HOURLY_RATE=r;
}
float Accounts::get_rate()const //shafeen
{
    return HOURLY_RATE;
}
void Accounts::set_total_working_hours(int t) // shafeen
{
    total_working_hours=t;
}
int Accounts::get_total_working_hours()const // shafeen
{
    return total_working_hours;
}
void Accounts::set_monthlySalary(float mSalary)
{
    monthlySalary=mSalary;
}
float Accounts::get_monthlySalary()const // shafeen
{
    return monthlySalary;
}
void Accounts::calculate_salary()// shafeen
{
    monthlySalary=HOURLY_RATE*total_working_hours;
}
void courseType::set_courses(vector<string> &c, int no)// shafeen
{
    for (int i = 0; i < no; i++)
    {
        courses_enrolled.push_back(c[i]);
    }
}
string courseType::get_courses()const // shafeen
{
    string s;
    for (int i = 0; i < courses_enrolled.size(); i++)
    {
        s+=courses_enrolled[i];
    }
    return s;
}
void courseType::set_marks(vector<float> &m, int no) // shafeen
{
    for (int i = 0; i < no; i++)
    {
        course_wise_marks.push_back(m[i]);
    }
}
float courseType::get_marks() const // shafeen
{
    float sum=0;
    for (int i = 0; i < course_wise_marks.size(); i++)
    {
        sum+=course_wise_marks[i];
    }
    return sum;
}
// void courseType::set_course_wise_attendance(vector<string> &s, int no)//    shafeen 
// {
//     for (int i = 0; i < no; i++)
//     {
//         s.push_back(s[i]);
//     }
// }
void courseType::set_courseId(string c)// shafeen
{
    courseId=c;
}
string courseType::get_courseId()const // shafeen
{
 return courseId;
}
void courseType::show_courses_enrolled()const  // shafeen
{
    for(int i = 0 ; i < courses_enrolled.size(); i++)   
    {
        cout<<courses_enrolled[i]<<endl;
    }
}
void courseType::show_course_wise_marks()const // shafeen
{
   for (int  i = 0; i < course_wise_marks.size(); i++)
   {
     cout<<course_wise_marks[i]<<endl;
   }
   
}
// void courseType::show_course_wise_attendance()const // shafeen
// {
//     for (int i = 0; i < course_wise_attendance.size(); i++)
//     {
//         cout<<course_wise_attendance[i]<<endl;
//     }
// }
// {
//     for (int i = 0; i < total_no_of_courses.size(); i++)
//     {
//         cout<<total_no_of_courses[i]<<endl;
//     }
    
// }
void courseType::set_marks_value(int student_no, float marks_value)
{
    course_wise_marks[student_no]=marks_value;
}
academicMemberType::academicMemberType() //shafeen
{ 
    
}
void academicMemberType::set_marks(vector<float> &m, int no) // shafeen
{
    for (int i = 0; i < no; i++)
    {
        marks.push_back(m[i]);
    }
}
float academicMemberType::get_marks(vector<float> &m,int &no)
{
    vector <employeeType> e;
    for (int i = 0; i < no; i++)
    {
        e[i].get_marks();
    }
}