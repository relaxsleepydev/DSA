// topological sorting using DFS
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void DFS(vector<int> adj[], int u, stack<int> &st, bool visited[])
{
    // pushing all the adjacent of a vertex 
    // and then itself in the stack using DFS
    visited[u] = true;
    for(int v:adj[u])
    {
        if(visited[v] == false)
        {
            DFS(adj, v, st, visited);
        }
    }
    st.push(u);
}

// calling DFS through this function
// and then just popping the top element
// from stack and printing and we get the
// topological sort of the given directed acyclic graph
void topologicalSort(vector<int> adj[], int V)
{
    bool visited[V];
    for(int i=0; i<V; i++)
    {
        visited[i] = false;
    }
    stack<int> st;

    for(int i=0; i<V; i++)
    {
        if(visited[i] == false)
        {
            DFS(adj, i, st, visited);
        }
    }

    while(st.empty() == false)
    {
        int u = st.top();
        st.pop();
        cout << u << " ";
    }
    cout << endl;
}

// for making the directed graph
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 4);

    topologicalSort(adj, V);
    return 0;
}