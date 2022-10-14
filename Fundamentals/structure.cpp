#include<iostream>
#include<string.h>
#include<windows.h>
using namespace std;
struct student{
    char name[20];
    int age;
};
int main(){
    struct student s1;
    //s1.name="brijehs";// we can not do like this because it is contain the address of first and can not reach at every
  strcpy(s1.name,"Brijesh");// it is the way to initializing string
  cout<<"Enter your name:";
  cin>>s1.name;
  cout<<"Age:";
   cin>>s1.age;
    cout<<"______________________________\n";
    cout<<"| Name: "<<s1.name<<"   |   Age: "<<s1.age<<"|"<<endl;
    cout<<"______________________________\n";

}
