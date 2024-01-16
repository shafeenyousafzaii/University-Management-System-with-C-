#include<iostream>
#include<string>
#include<vector>
using namespace std;
class dateType
{
int date;
int month;
int year;

public:

   dateType(int d=1,int m=1 , int y=2000);//KAshif
   void setDate(int d ,int m ,int y);
   void getDate(int &d, int &m ,int &y)const;

};

enum status{present,absent,late};//Kashif

class attendanceType
{
dateType date;//KAshif
status  _status;//KAshif

public :

  attendanceType(int d=1,int m=1 , int y=2000,status s=present);//KAshif
  void setStatusOnly(char s);
  void setDateOnly(int d,int m, int y);//KAshif
  void getStatus(int &d,int &m, int &y,char &s)const;
};

