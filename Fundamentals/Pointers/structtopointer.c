/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
struct rec 
{
    int l;
    int b;
};
int main()
{
    struct rec r={5,6};
    struct rec *p=&r;
    printf("%d\n%d",p->l,p->b);


    return 0;
}
