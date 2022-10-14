#include<iostream>
using namespace std;

class Rec
{
    int n;
public:
    Rec(int x)
    {
        n=x;
    }
    int Fact(int n)
    {
        if(n>1)
        {
            return(n*Fact(n-1));
        }
        else
        {
            return 1;
        }

    }
};
int main()
{
    int x,F;
    cin>>x;
    Rec r(x);
    F=r.Fact(x);
    cout<<x<<"!= "<<F;

}

