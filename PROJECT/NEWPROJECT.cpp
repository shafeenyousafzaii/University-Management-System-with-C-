#include<iostream>
#include<iomanip>
#include"NEW PROJECT.h"
using namespace std;
void    courseType::setCourseInfo(string    cName,    string    cNo,
int    credits)
{
courseName    =    cName;
courseNo    =    cNo;
courseCredits    =    credits; 
}   //end    setCourseInfo

void    courseType::print(ostream&    outF)
{
//Step    1
outF    <<    left;
outF    <<    setw(8)    <<    courseNo    <<    "              ";                                 //Step    2
//Step 3 
//Step 4
outF    <<    setw(15)    <<    courseName; 
outF    <<    right;
outF    <<    setw(3)    <<    courseCredits    <<    "              ";         //Step    5
}   //end    print

courseType::courseType(string    cName,    string    cNo,    int    credits) 
{
courseName    =    cName;
courseNo    =         cNo;
courseCredits    =    credits; 
}   //end    default    constructor
int    courseType::getCredits()
{
return    courseCredits; 
}   //end    getCredits
string    courseType::getCourseNumber()
{
return    courseNo; 
}//end    getCourseNumber
string    courseType::getCourseName()
{
return    courseName; 
}   //end    getCourseName