#include<iostream>
#include<stdlib.h>
using namespace std;
class Node
{
    public:
        int data;
        Node *next;
};
class LinkedStack
{
        Node *top;
    public:
        LinkedStack()
        {
            top = NULL;
        }
        void push()
        {
            Node *current = new Node();
            if(current != NULL)
            {
                int value;
                cout<<"\nEnter a value: ";
                cin>>value;
                current->data = value;
                current->next = top;
                top = current;
            }
            else
            {
                cout<<"\nMemory is not available\n";
            }
        }
        void traverse()
        {
            if(top != NULL)
            {
                cout<<"\nValue of stack are\n";
                Node *pos = top;
                while(pos != NULL)
                {
                    cout<<pos->data<<endl;
                    pos = pos->next;
                }
            }
            else
            {
                cout<<"\nNo element to traverse\n";
            }
        }
        void pop()
        {
            if(top != NULL)
            {
                Node *pos = top;
                top = top->next;
                int value = pos->data;
                delete pos;
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
    LinkedStack s;
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
