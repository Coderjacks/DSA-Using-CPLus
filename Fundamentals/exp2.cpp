#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{

    char str[10]={'B','H','O','P','A','L',0,};
    for(int i=0;str[i];i++)
    {
        cout<<str[i];

    }
    cout<<"\n"<<str;

    cout<<"\n";
    cin.getline(str,10);
    cout<<str;

}
