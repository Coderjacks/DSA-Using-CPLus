#include<iostream>
using namespace std;
int factorial(int n)
{
    if(n > 1)
    {
        return n * factorial(n - 1);
    }
    else
    {
        return 1;
    }
}
int main()
{
    int n, f;
    cout<<"Enter the number\n";
    cin>>n;
    f = factorial(n);
    cout<<"Factorial of "<<n<<" is "<<f;
    return 0;
}
