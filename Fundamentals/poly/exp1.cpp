#include<iostream>
using namespace std;
class demo
{
    int x;
    int y;
public:
    demo(int a,int b)
    {

        x=a;
        y=b;
        cout<<"Constructor calling\n";
        cout<<x<<endl;
        cout<<y<<endl;
    }
    void display()
    {
        cout<<"Display calling\n";
        cout<<x<<endl;
        cout<<y<<endl;
    }
    void operator +(demo d)
    {
        cout<<"polymorphism \n";
        d.x=x+d.x;
        d.y=y+d.y;
    }
};
int main()
{
    demo d1(20,30),d2(2,3);
    d1.display();
    d2.display();
    d3=d1+d2;
}
