#include<iostream>
#include<stdlib.h>
using namespace std;
class Stack
{
    int stack[5];
    int top;
public:
    Stack()
    {
        top = -1;
    }
    void push(int value)
    {
        top++;
        stack[top] = value;
    }
    int pop()
    {
        int value = stack[top];
        top--;
        return value;
    }
    bool is_empty()
    {
        if(top == -1)
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
    Stack st;
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
    void depth_first_search(int s, int n)
    {
        st.push(s);
        visited[s] = 1;
        cout<<"\nDFS Traversal of Graph\n";
        while(!st.is_empty())
        {
            int v = st.pop();
            cout<<v<<" ";
            for(int i = 0; i < n; i++)
            {
                if(edges[v][i] != 0 && !visited[i])
                {
                    st.push(i);
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
	g.depth_first_search(s, v);
}
