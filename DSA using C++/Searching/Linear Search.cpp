#include<iostream>
#include<stdlib.h>
using namespace std;
class Array
{
   int data[10];
   int MAX;
   int length;
   public:
       Array()
       {
            MAX = 10;
            length = 0;
       }
       void insert_at_end()
       {
           if(length < MAX)
           {
               int value;
               cout<<"\nEnter the value\n";
               cin>>value;
               data[length] = value;
               length++;
           }
           else
           {
               cout<<"\nArray is full\n";
           }
       }
       void traverse()
       {
           if(length > 0)
           {
                cout<<"\nValue of array are\n";
                for(int i = 0; i <= length - 1; i++)
                {
                    cout<<data[i]<<" ";
                }
                cout<<endl;
           }
           else
           {
               cout<<"\nNo value to traverse\n";
           }
       }
       void linearsearch()
       {
           int value, pos;
           pos = -1;
           cout<<"\nEnter the value: ";
           cin>>value;
           for(int i = 0; i <= length - 1; i++)
           {
               if(value == data[i])
               {
                   pos = i;
                   cout<<"\n"<<value<<" is present at index "<<pos<<endl;
                   break;
               }
           }
           if(pos == -1)
           {
               cout<<value<<" is not present\n";
           }
       }
};
int main()
{
    Array a;
    int ch;
    do
    {
        cout<<"\nEnter 1 to add value at end of array\n";
        cout<<"Enter 2 to traverse values of array\n";
        cout<<"Enter 3 to search a value in array\n";
        cout<<"Enter 4 to exit from program\n";
        cout<<"\nEnter your choice\n";
        cin>>ch;
        switch(ch)
        {
        case 1:
            a.insert_at_end();
            break;
        case 2:
            a.traverse();
            break;
        case 3:
            a.linearsearch();
            break;
        case 4:
            exit(0);
        default:
            cout<<"\nWrong choice entered\n";
        }
    }while(true);
    return 0;
}
