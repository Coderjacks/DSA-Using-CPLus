#include<iostream>
using namespace std;
struct student
{
    int roll_no;
    char name[10];
    int age;
};
int main()
{
    student *s = new student;
    cout<<"Enter roll number, name of student and age of student\n";
    cin>>s->roll_no>>s->name>>s->age;
    cout<<"Roll number: "<<s->roll_no<<"\nName: "<<s->name<<"\nAge: "<<s->age;
    delete s;
    return 0;
}
