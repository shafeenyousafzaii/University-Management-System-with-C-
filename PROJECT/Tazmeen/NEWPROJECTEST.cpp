#include<iostream>
#include<string>
#include<iomanip>
#include"NEWPROJECT.h"
#include<gdiplusgraphics.h>
#include<
using namespace std;
int main()
{ 
    dateType d1(1,1,2000);
    d1.getDate();
    attendanceType a1(1,1,2000,present);
    a1.getStatus();
    // employeeType e1
    // e1.set_data("Kashif","123","kashif@gmail.com","Karachi","Teacher",1);
    // e1.get_data();
    // e1.show_payments_details();
    facultyMemberType f1;
    f1.set_data("Kashif","123","Kashif@gmail.com","Karachi","Teacher",1);


}