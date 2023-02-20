#include<iostream>
using namespace std;
class Edge
{
public:
    int start_vertex;
    int end_vertex;
    int weight;
};
class Graph
{
    Edge edges[10];
    int no_of_vertices;
    int no_of_edges;
public:
    Graph(int v, int e)
    {
        no_of_vertices = v;
        no_of_edges = e;
        for(int i = 0; i <= no_of_edges - 1; i++)
        {
            cout<<"\nEnter starting vertex, end vertex and their weight\n";
            cin>>edges[i].start_vertex>>edges[i].end_vertex>>edges[i].weight;
        }
    }
    int find_parent(int vertex, int parents[])
    {
        if(parents[vertex] == vertex)
        {
            return vertex;
        }
        return find_parent(parents[vertex], parents);
    }
    void kruskals()
    {
        for(int i = 1; i <= no_of_edges - 1; i++)
        {
            for(int j = 0; j <= no_of_edges - 1 - i; j++)
            {
                if(edges[j].weight > edges[j + 1].weight)
                {
                    Edge temp = edges[j];
                    edges[j] = edges[j + 1];
                    edges[j + 1] = temp;
                }
            }
        }
        int parents[10];
        for(int i = 0; i <= no_of_vertices - 1; i++)
        {
            parents[i] = i;
        }
        Edge spanning_edges[10];
        int i = 0;
        int c = 0;
        while(c <= no_of_vertices - 2)
        {
            int start_vertex_parent = find_parent(edges[i].start_vertex, parents);
            int end_vertex_parent = find_parent(edges[i].end_vertex, parents);
            if(start_vertex_parent != end_vertex_parent)
            {
                spanning_edges[c] = edges[i];
                parents[start_vertex_parent] = end_vertex_parent;
                c++;
            }
            i++;
        }
        cout<<"\nEdge\t\tWeight\n";
        for(int i = 0; i <= no_of_vertices - 2; i++)
        {
            cout<<"("<<spanning_edges[i].start_vertex
            <<" - "<<spanning_edges[i].end_vertex
            <<")\t\t"<<spanning_edges[i].weight<<endl;
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
	g.kruskals();
}
