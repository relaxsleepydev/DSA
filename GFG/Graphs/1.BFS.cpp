// BFS 
// case 1 : source vertex is given and graph is not disconnected
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<int> adj[], int V, int s) {
    bool visited[V];
    for(int i=0; i<V; i++) {
        visited[i] = false;
    }

    queue<int> q;
    visited[s] = true;
    q.push(s);

    while(q.empty() == false) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for(int v: adj[u]) {
            if(visited[v] == false) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    int V=5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 2, 4);

    cout << "BFS of the graph : " << endl;
    BFS(adj, V, 0);

    return 0;
}

// case 2: no source vertex given and graph may be disconnected
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<int> adj[], int s, bool visited[]) {
    queue<int> q;

    visited[s] = true;
    q.push(s);

    while(q.empty() == false) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for(int v: adj[u]) {
            if(visited[v] == false) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void BFSDis(vector<int> adj[], int V) {
    bool visited[V];
    for(int i=0; i<V; i++) {
        visited[i] = false;
    }

    for(int i=0; i<V; i++) {
        if(visited[i] == false) {
            BFS(adj, i, visited);
        }
    }
}

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    int V = 7;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 6);
    addEdge(adj, 4, 6);

    cout << "BFS of the following graph : " << endl;
    BFSDis(adj, V);

    return 0;
}

// No of islands in a graph problem
// To find number of connected components in an undirected graph
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<int> adj[], int s, bool visited[]) {
    queue<int> q;

    visited[s] = true;
    q.push(s);

    while(q.empty() == false) {
        int u = q.front();
        q.pop();

        for(int v: adj[u]) {
            if(visited[v] == false) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int BFSDis(vector<int> adj[], int V) {
    bool visited[V];
    int count = 0;
    for(int i=0; i<V; i++) {
        visited[i] = false;
    }

    for(int i=0; i<V; i++) {
        if(visited[i] == false) {
            BFS(adj, i, visited);
            count++;
        }
    }

    return count;
}

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    int V = 7;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 6);
    addEdge(adj, 4, 6);

    cout << "Number of connected components : " << endl;
    cout << BFSDis(adj, V) << endl;

    return 0;
}