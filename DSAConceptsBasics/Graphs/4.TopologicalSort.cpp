// Topological Sort:
// here we sort in order of dependencies of vertices and this is for DAG.
// DAG => Directed Acyclic Graph is a graph which doesnt form cycle and is directed. 
// (u->v not u-v)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void add_edge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
}

void dfs(int node, vector<bool> &visited, vector<int> &st, vector<vector<int>> &adj)
{
    visited[node] = true;
    for(auto x: adj[node])
    {
        if(!visited[x])
        {
            dfs(x, visited, st, adj);
        }
    }
    st.push_back(node);
}

vector<int> topoSort(int n, vector<vector<int>> &adj)
{
    vector<bool> visited(n, false);
    vector<int> st;
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            dfs(i, visited, st, adj);
        }
    }
    reverse(st.begin(), st.end());
    return st;
}

int main()
{
    vector<vector<int>> adj(6);
    add_edge(adj, 5, 0);
    add_edge(adj, 5, 4);
    add_edge(adj, 3, 0);
    add_edge(adj, 3, 2);
    add_edge(adj, 4, 1);
    add_edge(adj, 2, 1);

    vector<int> res = topoSort(6, adj);
    for(auto x: res)
    {
        cout << x << " ";
    }

    return 0;
}