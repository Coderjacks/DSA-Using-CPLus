#include<iostream>
#include<stdlib.h>
using namespace std;
class ArrayStack
{
    int data[3];
    int max_size;
    int top;
public:
    ArrayStack()
    {
        max_size = 3;
        top = -1;
    }
    void push()
    {
        if(top < max_size - 1)
        {
            int value;
            cout<<"\nEnter a value: ";
            cin>>value;
            top++;
            data[top] = value;
        }
        else
        {
            cout<<"\nStack is full\n";
        }
    }
    void traverse()
    {
        if(top != -1)
        {
            cout<<"\nValues of stack are\n";
            for(int i = top; i >= 0; i--)
            {
                cout<<data[i]<<endl;
            }
        }
        else
        {
            cout<<"\nNo element to traverse\n";
        }
    }
    void pop()
    {
        if(top != -1)
        {
            int value = data[top];
            top--;
            cout<<"\nValue popped from stack: "<<value<<endl;
        }
        else
        {
            cout<<"\nStack is empty\n";
        }
    }
};
int main()
{
    ArrayStack s;
    int ch;
    do
    {
        cout<<"\nEnter 1 to push into stack\n";
        cout<<"\nEnter 2 to traverse stack\n";
        cout<<"\nEnter 3 to pop from stack\n";
        cout<<"\nEnter 4 to exit from program\n";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            s.push();
            break;
        case 2:
            s.traverse();
            break;
        case 3:
            s.pop();
            break;
        case 4:
            exit(0);
        default:
            cout<<"\nWrong choice entered\n";
        }
    }while(true);
    return 0;
}
