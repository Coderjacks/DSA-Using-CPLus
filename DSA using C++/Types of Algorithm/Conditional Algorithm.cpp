#include<iostream>
using namespace std;
int main()
{
    int n1, n2;
    cout<<"Enter first number\n";
    cin>>n1;
    cout<<"Enter second number\n";
    cin>>n2;
    if(n1 > n2)
    {
        cout<<n1<<" is greater than "<<n2;
    }
    else if(n2 > n1)
    {
        cout<<n2<<" is greater than "<<n1;
    }
    else
    {
        cout<<n1<<" is equal to "<<n2;
    }
    return 0;
}
