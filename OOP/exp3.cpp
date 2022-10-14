#include<iostream>
using namespace std;
class greatest
{
    int n1;
public:
    greatest(int a)
    {
        n1=a;
    }
    void p()
    {
     for(int i=0; i<n1; i++)
        {

            cout<<i;
        }
    }
};
int main()
{
    int x;
    cout<<"Enter a numbers"<<endl;
    cin>>x;
    greatest a1(x);
    a1.p();
}

