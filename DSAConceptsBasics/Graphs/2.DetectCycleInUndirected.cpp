// here, i just have to detect cycle in undirected graph:
// using DFS
#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, int parent)
{
    visited[node] = true;
    for(int i: adj[node])
    {
        if(!visited[i])
        {
            if(dfs(i, adj, visited, node))
            {
                return true;
            }
        }
        else if(i != parent)
        {
            return true;
        }
    }
    return false;
}

bool isCycle(vector<vector<int>> &adj)
{
    int V = adj.size();

    vector<bool> visited(V, false);
    for(int i=0; i<V; i++)
    {
        if(!visited[i])
        {
            if(dfs(i, adj, visited, -1))
            {
                return true;
            }
        }
    }
    return false;
}

void add_edge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    int V = 4;
    vector<vector<int>> adj(4);
    add_edge(adj, 0, 1);
    add_edge(adj, 0, 2);
    add_edge(adj, 1, 2);
    add_edge(adj, 2, 3);
    isCycle(adj) ? cout << "true" : cout << "false";
    return 0;
}

// using BFS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bfs(int node, vector<vector<int>> &adj, vector<bool> &visited)
{
    queue<pair<int, int>> q;
    q.push({node, -1});
    visited[node] = true;

    while(!q.empty())
    {
        int currNode = q.front().first;
        int parNode = q.front().second;
        q.pop();

        for(int neighbour: adj[currNode])
        {
            if(!visited[neighbour])
            {
                visited[neighbour] = true;
                q.push({neighbour, currNode});
            }

            else if(neighbour != parNode)
            {
                return true;
            }
        }
    }
    return false;
}

bool isCycle(vector<vector<int>> &adj)
{
    int V = adj.size();

    vector<bool> visited(V, false);
    for(int i=0; i<V; i++)
    {
        if(!visited[i])
        {
            if(bfs(i, adj, visited))
            {
                return true;
            }
        }
    }
    return false;
}

void add_edge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    int V = 4;
    vector<vector<int>> adj(4);
    add_edge(adj, 0, 1);
    add_edge(adj, 0, 2);
    add_edge(adj, 1, 2);
    add_edge(adj, 2, 3);
    isCycle(adj) ? cout << "true" : cout << "false";
    return 0;
}