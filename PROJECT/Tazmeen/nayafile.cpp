#include<iostream>
#include<string>
class A
{
    int x;
    public :
    A();
};
class B
{
private:
static int size;
   A *p;
public:
    B();
    // ~B();
};
int B::size=1;
B::B()
{
    p=new A[size];
    
}
int main()
{ 


}