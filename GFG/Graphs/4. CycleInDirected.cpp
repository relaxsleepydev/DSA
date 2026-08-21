// detecting cycle in a directed graph
// i can use DFS in this one i just have to think how to do that
#include <iostream>
#include <vector>
using namespace std;

bool DFSRec(vector<int> adj[], int s, bool visited[], bool recStk[])
{
    visited[s] = true;
    recStk[s] = true;
    for(int x: adj[s])
    {
        if(visited[x] == false && ( DFSRec(adj, x, visited, recStk) == true ))
        {
            return true;
        }
        else if(recStk[x] == true)
        {
            return true;
        }
    }
    recStk[s] = false;
    return false;
}

bool DFS(vector<int> adj[], int V)
{
    bool visited[V];
    bool recStk[V];
    for(int i=0; i<V; i++)
    {
        visited[i] = false;
        recStk[i] = false;
    }
    for(int i=0; i<V; i++)
    {
        if(visited[i] == false)
        {
            if(DFSRec(adj, i, visited, recStk) == true)
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
}

int main()
{
    int V=6;
	vector<int> adj[V];
	addEdge(adj,0,1); 
	addEdge(adj,2,1); 
	addEdge(adj,2,3); 
	addEdge(adj,3,4); 
	addEdge(adj,4,5);
	addEdge(adj,5,3);

    if (DFS(adj, V))
    {
        cout << "Cycle found" << endl;
    }
    else
    {
        cout << "No Cycle found" << endl;
    }

    return 0;
}