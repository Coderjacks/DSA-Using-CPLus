#include<stdio.h>
#define p printf
#define s scanf
#define m main
struct student
{
    int rollno;
    char name[20];
    int age;
};
int m()
{
    struct student s1,s2;
    //initialization
    s1.rollno=201;
    s1.age=20;
    s2.rollno=202;
    s2.age=19;
    gets(s1.name);
    gets(s1.name);
    p("details of first student\n");
    p("rollno= %10.d\n name= %10.s\n age= %10.d\n",s1.rollno,s1.name,s1.age);
    p("details of Second  student\n");
    p("rollno= %10.d\n name= %10.s\n age= %10.d\n",s2.rollno,s2.name,&s2.age);
}
