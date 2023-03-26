#include<iostream>
#include<stdlib.h>
using namespace std;
class Queue
{
    int queue[5];
    int front, rear;
public:
    Queue()
    {
        front = -1;
        rear = -1;
    }
    void enqueue(int value)
    {
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
    int dequeue()
    {
        int value = queue[front];
        if(front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
        return value;
    }
    bool is_empty()
    {
        if(front == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
class Graph
{
    int edges[5][5], visited[5];
    Queue q;
public:
    Graph(int v, int e)
    {
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                edges[i][j] = 0;
            }
        }
        for(int i = 0; i < 5; i++)
        {
            visited[i] = 0;
        }
        for(int i = 1; i <= e; i++)
        {
            int sv, ev;
            cout<<"\nEnter starting vertex and ending vertex\n";
            cin>>sv>>ev;
            edges[sv][ev] = 1;
        }
        cout<<"\nAdjacency matrix of Graph\n";
        for(int i = 0; i < v; i++)
        {
            for(int j = 0; j < v; j++)
            {
                cout<<edges[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void breadth_first_search(int s, int n)
    {
        q.enqueue(s);
        visited[s] = 1;
        cout<<"\nBFS Traversal of graph\n";
        while(!q.is_empty())
        {
            int v = q.dequeue();
            cout<<v<<" ";
            for(int i = 0; i < n; i++)
            {
                if(edges[v][i] == 1 && !visited[i])
                {
                    q.enqueue(i);
                    visited[i] = 1;
                }
            }
        }
    }
};
int main()
{
    int s, v, e;
    cout<<"\nEnter number of vertices in graph\n";
    cin>>v;
    cout<<"\nEnter number of edges in graph\n";
    cin>>e;
	Graph g(v, e);
	cout<<"\nEnter the source vertex\n";
	cin>>s;
	g.breadth_first_search(s, v);
}
