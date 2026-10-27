// Graph is a non-linear DS representing relationships
// between objects (made up of vertices k/a nodes and 
// edges k/a connections).

// Implementation of Graphs:
// 1. using adjacency matrix: 
// square matrix (2D vector) and straightforward way
#include <iostream>
#include <vector>
using namespace std;

class Graph {
    vector<vector<int>> adj_matrix;

    public:
    Graph(int n)
    {
        adj_matrix = vector<vector<int>>(n, vector<int>(n, 0));
    }

    void add_edge(int u, int v)
    {
        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1; // if undirected graph
    }

    void print()
    {
        cout << "Adjacency Matrix for the Graph: " << endl;
        int n = adj_matrix.size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout << adj_matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n = 4;
    Graph g(n);

    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);
    g.add_edge(2, 3);

    g.print();

    return 0;
}

// 2. Using Adjacency List:
// common way of representating a graph
// here adjList is of type <int, list<int>>
// where first will represent the node and second will
// is linnked list which represent the list of nodes
// that have connection with that node.
#include <iostream>
#include <list>
#include <map>
using namespace std;

class Graph {
    map<int, list<int>> adj_list;

    public:
    void add_edge(int u, int v)
    {
        adj_list[u].push_back(v);
        adj_list[v].push_back(u); // if undirected
    }

    void print()
    {
        cout << "Adjacency List for the Graph: " << endl;
        for(auto i: adj_list)
        {
            cout << i.first << " -> ";
            for(auto j: i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g;

    g.add_edge(1, 0);
    g.add_edge(2, 0);
    g.add_edge(1, 2);

    g.print();

    return 0;
}

// Graph Traversals:
// 1. BFS(Breadth First Search):
// when source vertex is given and undirected graph
#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

class Graph {
    map<int, list<int>> adj_list;

    public:
    void add_edge(int u, int v)
    {
        adj_list[u].push_back(v);
        adj_list[v].push_back(u); // Undirected graph
    }

    void print()
    {
        cout << "Adjacency List for the Graph: " << endl;
        for(auto i: adj_list)
        {
            cout << i.first << " -> ";
            for(auto j: i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    vector<int> bfs(int s)
    {
        vector<int> res;
        unordered_map<int, bool> visited; // Tracks visited status for any integer vertex ID
        queue<int> q;

        visited[s] = true;
        q.push(s);

        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            res.push_back(curr);

            // Traverse adjacent vertices of current node
            for(int neighbor : adj_list[curr])
            {
                if(!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        return res;
    }
};

int main()
{
    Graph g;

    g.add_edge(1, 2);
    g.add_edge(1, 0);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(2, 4);

    cout << "BFS Traversal starting from vertex 0:" << endl;
    vector<int> res = g.bfs(0);

    for(int node : res)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

// when source isnt given, disconnected, undirected graph
#include <iostream>
#include <list>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    map<int, list<int>> adj_list;

    void bfsConnected(int src, unordered_map<int, bool> &visited, vector<int> &res) {
        queue<int> q;
        visited[src] = true;
        q.push(src);

        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            res.push_back(curr);
            for(int x: adj_list[curr])
            {
                if(!visited[x])
                {
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
    }

    public:
    void add_edge(int u, int v)
    {
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    void print()
    {
        cout << "Adjacency List for the Graph: " << endl;
        for(auto i: adj_list)
        {
            cout << i.first << " -> ";
            for(auto j: i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    vector<int> bfs() 
    {
        unordered_map<int, bool> visited;
        vector<int> res;

        for(auto pair: adj_list)
        {
            int node = pair.first;
            if(!visited[node])
            {
                bfsConnected(node, visited, res);
            }
        }
        return res;
    }
};

int main() {
    Graph g;
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(0, 3);
    g.add_edge(4, 5);

    cout << "BFS Traversal for Disconnected Graph: " << endl;
    vector<int> res = g.bfs();
    for(int node: res)
    {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}

// 2. DFS (Depth First Traversal):
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <list>
using namespace std;

class Graph {
    map<int, list<int>> adj_list;

    public:
    void add_edge(int u, int v)
    {
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    void print()
    {
        for(auto x: adj_list)
        {
            cout << x << " -> ";
            for(auto y: x.second)
            {
                cout << y << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g;
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 0);

    g.print();

    return 0;
}
