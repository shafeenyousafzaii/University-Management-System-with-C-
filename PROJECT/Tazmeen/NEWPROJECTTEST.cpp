#include<iostream>
#include<string>
#include<iomanip>
#include"NEWPROJECT.h"
using namespace std;
void getStudentData(ifstream &,studentType studentList[],int NOS);
void printGradeReports(ofstream &, studentType studentList[], int numberOfStudents, double tuitionRate);
int main()
{
  studentType studentList[MAX_NO_OF_STUDENTS];
  int noOfStudents;
  double tuitionRate;
  ifstream infile;
  ofstream outfile;
  infile.open("C:/Users/Shafeen/Documents/My-all-programs--/PROJECT/Tazmeen/stData.txt");
  if (!infile)
  {
    cout << "The    input    file    does    not    exist.    "
         << "Program    terminates." << endl;
    return 1;
  }
  outfile.open("a.txt");
  infile >> noOfStudents;
  infile >> tuitionRate;
  getStudentData(infile, studentList, noOfStudents);
  printGradeReports(outfile, studentList,
                    noOfStudents, tuitionRate);
  return 0;
}

void getStudentData(ifstream &infile, studentType studentList[], int numberOfStudents)
{
  // local    variables
  string fName;
  string lName;
  int ID;
  int noOfCourses;
  char isPaid;
  bool isTuitionPaid;
  string cName;
  string cNo;
  int credits;
  int count;
;  int i;
  vector<courseType> courses;

  vector<char> cGrades;
  for (count = 0; count < numberOfStudents; count++)
  {
    infile >> fName >> lName >> ID >> isPaid; // Step    1
    if (isPaid == 'Y')
      isTuitionPaid = true;
    else
      isTuitionPaid = false;
    infile >> noOfCourses;

    for (i = 0; i < noOfCourses; i++)
    {
      infile >> cName >> cNo >> credits >> cGrades[i];
      courses[i].setCourseInfo(cName, cNo,
                               credits);
    }
    studentList[count].setInfo(fName, lName, ID, noOfCourses, isTuitionPaid, courses, cGrades);
  }
}

void printGradeReports(ofstream &outfile, studentType studentList[], int numberOfStudents, double tuitionRate)
{
  int count;
  for (count = 0; count < numberOfStudents; count++)
    studentList[count].print(outfile, tuitionRate);
}