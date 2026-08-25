// detect cycle in an undirected graph
#include <iostream>
#include <vector>
using namespace std;

bool DFSRec(vector<int> adj[], int s, bool visited[], int parent)
{
    visited[s] = true;
    for(int v: adj[s])
    {
        if(visited[v] == false)
        {
            if(DFSRec(adj, v, visited, s) == true)
            {
                return true;
            }
        }
        else if(v != parent)
        {
            return true;
        }
    }
    return false;
}

bool DFS(vector<int> adj[], int V)
{
    bool visited[V];
    for(int i=0; i<V; i++)
    {
        visited[i] = false;
    }
    for(int i=0; i<V; i++)
    {
        if(visited[i] == false)
        {
            if(DFSRec(adj, i, visited, -1) == true)
            {
                return true;
            }
        }
    }
    return false;
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    int V = 6;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 4, 5);

    cout << DFS(adj, V) << endl;

    return 0;
}