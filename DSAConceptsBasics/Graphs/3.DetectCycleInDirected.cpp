// Detecting cycle in Directed Graph:
// 1. using DFS:
#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<vector<int>> &adj, int u, vector<bool> visited, vector<bool> recStack)
{
    if(recStack[u])
    {
        return true;
    }

    if(visited[u])
    {
        return false;
    }

    visited[u] = true;
    recStack[u] = true;

    for(int v: adj[u])
    {
        if(dfs(adj, v, visited, recStack))
        {
            return true;
        }
    }

    recStack[u] = false;
    return false;
}

bool isCycle(int V, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V);
    for(auto& edge: edges)
    {
        adj[edge[0]].push_back(edge[1]);
    }

    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);

    for(int i=0; i<V; i++)
    {
        if(!visited[i] && dfs(adj, i, visited, recStack))
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int V=4;
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 0},
        {2, 3}
    };

    cout << (isCycle(V, edges) ? "true": "false") << endl;

    return 0;
}

// 2. using BFS(Kahn's Algo)
#include <bits/stdc++.h>
using namespace std;

bool isCyclic(int V, vector<vector<int>>& edges)
{
    vector<vector<int>> adj(V);

    // Create adjacency list
    for (auto& edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
    }

    // Array to store in-degree of each vertex
    vector<int> inDegree(V, 0);

    queue<int> q;

    // Count of visited (processed) nodes
    int visited = 0;

    // Compute in-degrees of all vertices
    for (int u = 0; u < V; u++)
    {
        for (int v : adj[u])
        {
            inDegree[v]++;
        }
    }

    // Add all vertices with in-degree 0 to the queue
    for (int u = 0; u < V; u++)
    {
        if (inDegree[u] == 0)
        {
            q.push(u);
        }
    }

    // Perform BFS (Topological Sort)
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        visited++;

        // Reduce in-degree of neighbors
        for (int v : adj[u])
        {
            inDegree[v]--;

            if (inDegree[v] == 0)
            {
                // Add to queue when in-degree becomes 0
                q.push(v);
            }
        }
    }

    // If visited nodes != total nodes, a cycle exists
    return visited != V;
}

int main()
{
    int V = 4;

    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {1, 2},
        {2, 3}
    };

    cout << (isCyclic(V, edges) ? "true" : "false") << endl;

    return 0;
}