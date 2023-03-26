#include<iostream>
#include<stdlib.h>
using namespace std;
class Node
{
    public:
        int data;
        Node *next;
};
class LinkedQueue
{
    Node *front, *rear;
public:
    LinkedQueue()
    {
        front = NULL;
        rear = NULL;
    }
    void enqueue()
    {
        Node *current = new Node;
        if(current != NULL)
        {
            int value;
            cout<<"\nEnter the value\n";
            cin>>value;
            current->data = value;
            if(front == NULL)
            {
                front = current;
            }
            else
            {
                rear->next = current;
            }
            rear = current;
            rear->next = NULL;
        }
        else
        {
            cout<<"\nMemory is not available\n";
        }
    }
    void traverse()
    {
        if(front != NULL)
        {
            Node *pos = front;
            cout<<"\nValues of queue are\n";
            while(pos != NULL)
            {
                cout<<pos->data<<" ";
                pos = pos->next;
            }
            cout<<endl;
        }
        else
        {
            cout<<"\nNo value to traverse\n";
        }
    }
    void dequeue()
    {
        if(front != NULL)
        {
            Node *pos = front;
            if(front != rear)
            {
                front = front->next;
            }
            else
            {
                front = rear = NULL;
            }
            int value = pos->data;
            delete pos;
            cout<<"\nDequeued value: "<<value<<endl;
        }
        else
        {
            cout<<"\nQueue is empty\n";
        }
    }
};
int main()
{
    int ch;
    LinkedQueue q;
    do
    {
        cout<<"\nEnter 1 to enqueue in linked queue\n";
        cout<<"\nEnter 2 to traverse linked queue\n";
        cout<<"\nEnter 3 to dequeue from linked queue\n";
        cout<<"\nEnter 4 to exit from program\n";
        cin>>ch;
        switch(ch)
        {
        case 1:
            q.enqueue();
            break;
        case 2:
            q.traverse();
            break;
        case 3:
            q.dequeue();
            break;
        case 4:
            exit(0);
        default:
            cout<<"\nWrong choice entered\n";
        }
    }while(true);
    return 0;
}
