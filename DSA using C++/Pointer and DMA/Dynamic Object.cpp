#include<iostream>
using namespace std;
class A
{
    int x, y;
public:
    A()
    {
        x = 1;
        y = 2;
    }
    void dispaly()
    {
        cout<<x<<endl<<y<<endl;
    }
};
int main()
{
    A *a = new A();
    a->dispaly();
    delete a;
    return 0;
}
