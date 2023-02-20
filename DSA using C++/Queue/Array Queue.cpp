#include<iostream>
#include<stdlib.h>
using namespace std;
class ArrayQueue
{
    int queue[3];
    int max;
    int front, rear;
public:
    ArrayQueue()
    {
        max = 3;
        front = -1;
        rear = -1;
    }
    void enqueue()
    {
        if(rear < max - 1)
        {
            int value;
            cout<<"\nEnter a value: ";
            cin>>value;
            if(front == -1)
            {
                front = 0;
                rear = 0;
            }
            else
            {
                rear++;
            }
            queue[rear] = value;
        }
        else
        {
            cout<<"\nQueue is full\n";
        }
    }
    void traverse()
    {
        if(front != -1)
        {
            cout<<"\nValue of queue are\n";
            for(int i = front; i <= rear; i++)
            {
                cout<<queue[i]<<" ";
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
        if(front != -1)
        {
            int value = queue[front];
            if(front != rear)
            {
                front++;
            }
            else
            {
                front = rear = -1;
            }
            cout<<"\nValue dequeued: "<<value<<endl;
        }
        else
        {
            cout<<"\nQueue is empty\n";
        }
    }
};
int main()
{
    ArrayQueue q;
    int ch;
    do
    {
        cout<<"\nEnter 1 to enqueue into queue\n";
        cout<<"\nEnter 2 to traverse queue\n";
        cout<<"\nEnter 3 to dequeue from queue\n";
        cout<<"\nEnter 4 to exit from program\n";
        cout<<"\nEnter your choice: ";
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
