#include<iostream>
using namespace std;
 int  add(int *a , int *b)
{

    int s=*a+*b;

}
int main()
{
    int a,b;
    cin>>a>>b;
    int s;
    s=add(&a,&b);
    cout<<"sum= "<<s<<endl;
}
