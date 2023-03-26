#include<iostream>
using namespace std;
#define INF 99999
class Graph
{
    int edges[5][5];
    int number_of_vertices;
    int number_of_edges;
public:
    Graph(int v, int e)
    {
        number_of_vertices = v;
        number_of_edges = e;
        for(int i = 0; i <= number_of_vertices - 1; i++)
        {
            for(int j = 0; j <= number_of_vertices - 1; j++)
            {
                edges[i][j] = 0;
            }
        }
        int sv, ev, w;
        for(int i = 1; i <= number_of_edges; i++)
        {
            cout<<"Enter the starting vertex, ending vertex and weight of the edge\n";
            cin>>sv>>ev>>w;
            edges[sv][ev] = w;
            edges[ev][sv] = w;
        }
        cout<<"Adjacency matrix of graph\n";
        for(int i = 0; i <= number_of_vertices - 1; i++)
        {
            for(int j = 0; j <= number_of_vertices - 1; j++)
            {
                cout<<edges[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void dijkistra(int source_vertex)
    {
        int distances[5], visited[5];
        for(int i = 0; i <= number_of_vertices - 1; i++)
        {
            distances[i] = INF;
            visited[i] = 0;
        }
        distances[source_vertex] = 0;
        for(int i = 0; i <= number_of_vertices - 1; i++)
        {
            int minimum = INF, minimum_vertex;
            for(int j = 0; j <= number_of_vertices - 1; j++)
            {
                if(!visited[j] && distances[j] < minimum)
                {
                    minimum = distances[j];
                    minimum_vertex = j;
                }
            }
            visited[minimum_vertex] = 1;
            for(int j = 0; j <= number_of_vertices - 1; j++)
            {
                if(edges[minimum_vertex][j] != 0 && !visited[j] && edges[minimum_vertex][j] < distances[j])
                {
                    distances[j] = distances[minimum_vertex] + edges[minimum_vertex][j];
                }
            }
        }
        cout<<"Vertex\tDistance\n";
        for(int i = 0; i <= number_of_vertices - 1; i++)
        {
            cout<<i<<"\t"<<distances[i]<<endl;
        }
    }
};
main()
{
    int v, e, sv;
    cout<<"Enter number of vertices and edges in graph\n";
    cin>>v>>e;
    Graph g(v, e);
    cout<<"Enter the source vertex of graph\n";
    cin>>sv;
    g.dijkistra(sv);
}
