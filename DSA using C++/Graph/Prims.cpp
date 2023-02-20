#include<iostream>
#include<stdlib.h>
using namespace std;
#define INF 99999
class Graph
{
    int edges[5][5];
    int weights[5];
    int visited[5];
    int parents[5];
    int no_of_vertices;
    int no_of_edges;
public:
    Graph(int v, int e)
    {
        no_of_vertices = v;
        no_of_edges = e;
        for(int i = 0; i <= no_of_vertices - 1; i++)
        {
            for(int j = 0; j <= no_of_vertices - 1; j++)
            {
                edges[i][j] = 0;
            }
        }
        for(int i = 1; i <= no_of_edges; i++)
        {
            int sv, ev, w;
            printf("\nEnter starting vertex, end vertex and their weight\n");
            scanf("%d%d%d", &sv, &ev, &w);
            edges[sv][ev] = w;
        }
        printf("\nAdjacency matrix of graph\n");
        for(int i = 0; i <= no_of_vertices - 1; i++)
        {
            for(int j = 0; j <= no_of_vertices - 1; j++)
            {
                printf("%d\t", edges[i][j]);
            }
            printf("\n");
        }
    }
    void prims(int source_vertex)
    {
        for(int i = 0; i <= no_of_vertices - 1; i++)
        {
            weights[i] = INF;
            visited[i] = 0;
            parents[i] = -1;
        }
        weights[source_vertex] = 0;
        for(int i = 1; i <= no_of_vertices - 1; i++)
        {
            int minimum = INF, minimum_vertex;
            for(int j = 0; j <= no_of_vertices - 1; j++)
            {
                if(!visited[j] and weights[j] < minimum)
                {
                    minimum = weights[j];
                    minimum_vertex = j;
                }
            }
            visited[minimum_vertex] = 1;
            for(int j = 0; j <= no_of_vertices - 1; j++)
            {
                if(edges[minimum_vertex][j] != 0 && !visited[j] && edges[minimum_vertex][j] < weights[j])
                {
                    weights[j] = edges[minimum_vertex][j];
                    parents[j] = minimum_vertex;
                }
            }
        }
        printf("\nEdge\tWeight\n");
        for(int i = 1; i <= no_of_vertices - 1; i++)
        {
            printf("%d - %d\t%d\n", parents[i], i, weights[i]);
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
	g.prims(s);
}
