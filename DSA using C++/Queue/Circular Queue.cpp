#include<iostream>
#include<stdlib.h>
using namespace std;
class CircularQueue
{
    int queue[5];
    int max;
    int front, rear;
public:
    CircularQueue()
    {
        max = 5;
        front = -1;
        rear = -1;
    }
    void enqueue()
    {
        if((front == 0 && rear == max - 1) || (front == rear + 1))
        {
            cout<<"\nCircular queue is full\n";
        }
        else
        {
            int value;
            if(front == -1)
            {
                front = 0;
                rear = 0;
            }
            else if(rear == max - 1)
            {
                rear = 0;
            }
            else
            {
                rear++;
            }
            cout<<"\nEnter a value: ";
            cin>>value;
            queue[rear] = value;
        }
    }
    void traverse()
    {
        if(front != -1)
        {
            cout<<"\nValues of queue are\n";
            if(front <= rear)
            {
                for(int i = front; i <= rear; i++)
                {
                    cout<<queue[i]<<" ";
                }
            }
            else
            {
                for(int i = front; i <= max - 1; i++)
                {
                    cout<<queue[i]<<" ";
                }
                for(int i = 0; i <= rear; i++)
                {
                    cout<<queue[i]<<" ";
                }
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
            if(front == rear)
            {
                front = rear = -1;
            }
            else if(front == max - 1)
            {
                front = 0;
            }
            else
            {
                front++;
            }
            cout<<"\nValue dequeued: "<<value<<endl;
        }
        else
        {
            cout<<"\nCircular queue is empty\n";
        }
    }
};
int main()
{
    CircularQueue q;
    int ch;
    do
    {
        cout<<"\nEnter 1 to enqueue into circular queue\n";
        cout<<"\nEnter 2 to traverse circular queue\n";
        cout<<"\nEnter 3 to dequeue from circular queue\n";
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
