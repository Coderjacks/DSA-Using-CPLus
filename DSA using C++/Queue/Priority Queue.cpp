#include<iostream>
#include<stdlib.h>
using namespace std;
class Node
{
    public:
        int data;
        int priority;
        Node *next;
};
class PriorityQueue
{
    Node *front, *rear;
public:
    PriorityQueue()
    {
        front = NULL;
        rear = NULL;
    }
    void enqueue()
    {
        Node *current = new Node;
        if(current != NULL)
        {
            int value, priority;
            cout<<"\nEnter the value: ";
            cin>>value;
            current->data = value;
            cout<<"\nEnter the priority: ";
            cin>>priority;
            current->priority = priority;
            if(front == NULL)
            {
                front = current;
                rear = current;
                rear->next = NULL;
            }
            else if(current->priority < front->priority)
            {
                current->next = front;
                front = current;
            }
            else
            {
                Node *p1 = front, *p2 = front->next;
                while(p1 != rear)
                {
                    if(current->priority > p1->priority && current->priority < p2->priority)
                    {
                        break;
                    }
                    p1 = p2;
                    p2 = p2->next;
                }
                if(p2 != NULL)
                {
                    p1->next = current;
                    current->next = p2;
                }
                else
                {
                    rear->next = current;
                    rear = current;
                    rear->next = NULL;
                }
            }
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
            cout<<"\nValues of priority queue are\n";
            while(pos != NULL)
            {
                cout<<pos->data<<"["<<pos->priority<<"] ";
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
            int priority = pos->priority;
            delete pos;
            cout<<"\nDequeued value: "<<value<<"["<<priority<<"]"<<endl;
        }
        else
        {
            cout<<"\nPriority queue is empty\n";
        }
    }
};
int main()
{
    int ch;
    PriorityQueue q;
    do
    {
        cout<<"\nEnter 1 to enqueue in priority queue\n";
        cout<<"\nEnter 2 to traverse priority queue\n";
        cout<<"\nEnter 3 to dequeue from priority queue\n";
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
