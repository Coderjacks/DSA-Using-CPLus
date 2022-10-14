/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include<stdio.h>
using namespace std;
void Swap(int x, int y)
{
    int temp;
    temp=x;
    x=y;
    y=temp;
}
int main()
{
    int a=10,b=20;
    Swap(a,b);
    cout<<a<<"\n"<<b<<"\n";


    return 0;
}