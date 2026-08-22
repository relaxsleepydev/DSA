// detecting cycle using Kahn's algo in a directed graph
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isCycleOrNot(vector<int> adj[], int V)
{
    int count=0;
    int in_degree[V];
    for(int i=0; i<V; i++)
    {
        for(int x: adj[i])
        {
            in_degree[x]++;
        }
    }

    queue<int> q;
    for(int i=0; i<V; i++)
    {
        if(in_degree[i] == 0)
        {
            q.push(i);
        }
    }

    while(q.empty()==false)
    {
        int u = q.front();
        q.pop();
        for(int v: adj[u])
        {
            if(--in_degree[v]==0)
            {
                q.push(v);
            }
        }
        count++;
    }
    return (count!=V);
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

int main()
{
    int V = 4;
    vector<int> adj[V];

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 2, 3);

    if(isCycleOrNot(adj, V))
    {
        cout << "Cycle detected" << endl;
    }
    else
    {
        cout << "No cycle detected" << endl;
    }
    return 0;
}