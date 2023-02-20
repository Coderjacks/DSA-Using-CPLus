#include<iostream>
using namespace std;
int main()
{
    int n, c;
    cout<<"Enter the number\n";
    cin>>n;
    c = 0;
    while(n > 0)
    {
        c++;
        n = n / 10;
    }
    cout<<"Number of digits is "<<c;
    return 0;
}
