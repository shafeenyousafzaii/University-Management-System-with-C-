#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
using namespace std;
const    int    MAX_NO_OF_STUDENTS    =    10;
class    personType
{ 
public:
void    print()    const;
void    setName(string    first,    string    last); 
string    getFirstName()    const;
string    getLastName()    const;
personType(string    first    =    "",    string    last    =    "");
private:
string    firstName;    
string    lastName;       
};
void    personType::print()    const
{
cout    <<    firstName    <<    "    "    <<    lastName;
}
void    personType::setName(string    first,    string    last) 
{
firstName    =    first; 
lastName    =    last;
}
string    personType::getFirstName()    const 
{
return    firstName; 
}
string    personType::getLastName()    const 
{return    lastName; 
}

personType::personType(string first, string last)
{
firstName    =    first; 
lastName    =    last;
}
//--------------------------------------------
class    courseType
{ 
public:
void    setCourseInfo(string    cName,    string    cNo,    int    credits); 
void    print(ostream&    outF);
int    getCredits();
string    getCourseNumber();
string    getCourseName();
courseType(string    cName    =    "",    string    cNo    =    "", int    credits    =    0);
private:
// courseCredits    =    credits;
string    courseName;        
string    courseNo;             
int    courseCredits;     //  
};
//-------------------------------------------------------------------------------------------------------------------
class    studentType:    public    personType 
{
public:
void    setInfo(string    fname,    string    lName,    int    ID,
int    nOfCourses,    bool    isTPaid,
courseType    courses[],    char    courseGrades[]);
void    print(ostream&    outF,    double    tuitionRate);
studentType();
int    getHoursEnrolled();
double getGpa();
double    billingAmount(double    tuitionRate);
private:
void    sortCourses();
int    sId;                                                            
int    numberOfCourses;    
bool    isTuitionPaid;     
courseType coursesEnrolled[6];
char coursesGrade[6]; 
};
//----------------------------------------------------------------------------------------------------------------------
void    courseType::setCourseInfo(string    cName,    string    cNo,
int    credits)
{
courseName    =    cName;
courseNo    =    cNo;
courseCredits    =    credits; 
}  //

void    courseType::print(ostream&    outF)
{
outF    <<    left;
outF    <<    setw(8)    <<    courseNo    <<    "              ";                     
outF    <<    setw(15)    <<    courseName; 
outF    <<    right;
outF    <<    setw(3)    <<    courseCredits    <<    "              ";        
}  //

courseType::courseType(string    cName,    string    cNo,    int    credits) 
{
courseName    =    cName;
courseNo    =         cNo;
courseCredits    =    credits; 
}  //
int    courseType::getCredits()
{
return    courseCredits; 
}  //
string    courseType::getCourseNumber()
{
return    courseNo; 
}//
string    courseType::getCourseName()
{
return    courseName; 
}//

void    studentType::setInfo(string    fName,    string    lName,    int    ID,
int    nOfCourses,    bool    isTPaid, 
courseType    courses[],    char    cGrades[])
{
int    i;
setName(fName,    lName);                                        
sId    =    ID;                                                                
isTuitionPaid    =    isTPaid;                                
numberOfCourses    =    nOfCourses;         
for    (i    =    0;    i    <    numberOfCourses;    i++) 
{
coursesEnrolled[i]   =    courses[i]; 
coursesGrade[i]   =    cGrades[i];
}
sortCourses();             
}   

studentType::studentType()
{
numberOfCourses    =    0; 
sId    =    0;
isTuitionPaid    =    false; 
for    (int    i    =    0;    i    <    6;    i++)
coursesGrade[i]   =    '*'; 
} 

void    studentType::print(ostream&    outF,    double    tuitionRate) 
{
int    i;
outF << "Student Name: " << getFirstName() <<    "    "    <<    getLastName()    <<    endl;
outF    <<    "Student    ID:    "    <<    sId    <<    endl;                             
outF    <<    "Number    of    courses    enrolled:    "<<    numberOfCourses    <<    endl; 
outF    <<    endl;
outF    <<    left;
outF    <<    "Course    No"    <<    setw(15)    <<    "         Course    Name"<<    setw(8)    <<    "Credits"<<    setw(6)    <<    "Grade"    <<    endl; 
outF    <<    right;
for    (i    =    0;    i    <    numberOfCourses;    i++) 
{
coursesEnrolled[i].print(outF); 
if    (isTuitionPaid)
{
outF    <<setw(4)    <<    coursesGrade[i]   <<    endl;
}
else
{outF    <<    setw(4)    <<    "***"    <<    endl;
}
}
outF    <<    endl;
outF << "Total number of credit hours: "<<    getHoursEnrolled()    <<    endl;
outF    <<setw(4)    <<    coursesGrade[i]   <<    endl; 
outF    <<    setw(4)    <<    "***"    <<    endl;
outF    <<    fixed    <<    showpoint    <<    setprecision(2);        
if    (isTuitionPaid)
outF    <<    "Mid-Semester    GPA:    "    <<    getGpa() <<    endl;
else
{
outF    <<    "***    Grades    are    being    held    for    not    paying    " <<    "the    tuition.    ***"    <<    endl;
outF    <<    "Amount    Due:    $"    <<    billingAmount(tuitionRate) <<    endl;
} 

outF    <<    "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" <<    "-*-*-*-*-"    <<    endl    <<    endl;

}

int    studentType::getHoursEnrolled() 
{
int    totalCredits    =    0; 
int    i;
for    (i    =    0;    i    <    numberOfCourses;    i++)
totalCredits    +=    coursesEnrolled[i].getCredits(); 
return    totalCredits;
}   
double    studentType::billingAmount(double    tuitionRate) 
{
return    tuitionRate    *    getHoursEnrolled(); 
}
  double    studentType::getGpa()
{
int    i;
double    sum    =    0.0;
for    (i    =    0;    i    <    numberOfCourses;    i++) 
{
switch    (coursesGrade[i]) 
{
case    'A':
sum    +=    coursesEnrolled[i].getCredits()    *    4; 
break;
case    'B':
sum    +=    coursesEnrolled[i].getCredits()    *    3; 
break;
case    'C':
sum    +=    coursesEnrolled[i].getCredits()    *    2; 
break;
case    'D':
sum    +=    coursesEnrolled[i].getCredits()    *    1; 
break;
case    'F': 
break;
default:
cout    <<    "Invalid    Course    Grade."    <<    endl;
} 
}
return sum / getHoursEnrolled();
}   
void    studentType::sortCourses() 
{
int    i,    j; 
int    minIndex;
courseType    temp;                  
char    tempGrade;                   
string    course1;
string    course2;
for    (i    =    0;    i    <    numberOfCourses    -    1;    i++) 
{
minIndex    =    i;
for    (j    =    i    +    1;    j    <    numberOfCourses;    j++) 
{
//get    the    course    numbers
course1    =
coursesEnrolled[minIndex].getCourseNumber(); 
course2    =    coursesEnrolled[j].getCourseNumber();
if    (course1    >    course2) 
minIndex    =    j;

}
temp    =    coursesEnrolled[minIndex];
coursesEnrolled[minIndex]   =    coursesEnrolled[i]; 
coursesEnrolled[i]   =    temp;
tempGrade    =    coursesGrade[minIndex]; 
coursesGrade[minIndex]   =    coursesGrade[i]; 
coursesGrade[i]   =    tempGrade;
}  
}   
void    getStudentData(ifstream&    infile,
studentType    studentList[], 
int    numberOfStudents)
{
//local    variables
string    fName;           
string    lName;    
int    ID;                                            
int    noOfCourses;    
char    isPaid;                   
bool    isTuitionPaid;  
string    cName;         
string    cNo;            
int credits; 
int    count;                            
int    i;                                             
courseType    courses[6];    

char    cGrades[6];                                
for    (count    =    0;    count    <    numberOfStudents;    count++)
{
infile    >>    fName    >>    lName    >>    ID    >>    isPaid;         //Step    1
if    (isPaid    ==    'Y') 
isTuitionPaid    =    true;
else
isTuitionPaid    =    false; 
infile    >>    noOfCourses;

for    (i    =    0;    i    <    noOfCourses;    i++)                                          
{
infile    >>    cName    >>    cNo    >>    credits
// Function 
// printGrade
// Reports
>>    cGrades[i];
courses[i].setCourseInfo(cName, cNo,
credits);                  
}
studentList[count].setInfo(fName,    lName,    ID,
noOfCourses, 
isTuitionPaid,
courses,    cGrades);   
}
}  


void    printGradeReports(ofstream&    outfile,
studentType    studentList[], 
int    numberOfStudents, 
double    tuitionRate)
{
int    count;
for    (count    =    0;    count    <    numberOfStudents;    count++) 
studentList[count].print(outfile,    tuitionRate);
}  

int    main() 
{
studentType    studentList[MAX_NO_OF_STUDENTS]; 
int    noOfStudents;
double    tuitionRate; 
ifstream    infile; 
ofstream    outfile;
infile.open("stData.txt"); 
if    (!infile)
{
cout    <<    "The    input    file    does    not    exist.    " 
<<    "Program    terminates."    <<    endl;
return    1; 
}
outfile.open("sDataOut.txt");
infile    >>    noOfStudents;    
infile    >>    tuitionRate;        
getStudentData(infile,    studentList,    noOfStudents); 
printGradeReports(outfile,    studentList,
noOfStudents,    tuitionRate);
return    0; 
}
