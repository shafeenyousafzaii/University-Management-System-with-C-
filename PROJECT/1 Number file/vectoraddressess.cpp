#include<iostream>
#include<string>
#include<vector>
using namespace std;

class studentType 
{
public:
  string name;
};

class B
{
public:
    vector<studentType*> students;
    void addstudentsFACULTY(studentType *s)
  {
     students.push_back(s);
  }


};


int main()
{
   vector<studentType> studentss;
   studentss.push_back(studentType());
   studentss.push_back(studentType());
   studentss[0].name="kashif";
   studentss[1].name="kashif402";
   B b;

   b.addstudentsFACULTY(&studentss[0]);
  b.addstudentsFACULTY(&studentss[1]);
   

    b.students[0]->name="Imtiaz";
    b.students[1]->name="shafeen";

    cout<<studentss[0].name<<endl;
    cout<<studentss[1].name<<endl;


   return 0;
}
