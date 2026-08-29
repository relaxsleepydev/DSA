#include <iostream>
#include <climits>
using namespace std;

class Graph {
public:
    int V;
    int** graph;

    Graph(int vertices) {
        V = vertices;
        graph = new int*[V];
        for (int i = 0; i < V; ++i) {
            graph[i] = new int[V];
            for (int j = 0; j < V; ++j) {
                graph[i][j] = 0;
            }
        }
    }

    void printMST(int parent[]) {
        cout << "Edge \tWeight\n";
        for (int i = 1; i < V; ++i) {
            cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
        }
    }

    int minKey(int key[], bool mstSet[]) {
        int min = INT_MAX;
        int min_index;

        for (int v = 0; v < V; ++v) {
            if (key[v] < min && !mstSet[v]) {
                min = key[v];
                min_index = v;
            }
        }

        return min_index;
    }

    void primMST() {
        int* key = new int[V];
        int* parent = new int[V];
        bool* mstSet = new bool[V];

        for (int i = 0; i < V; ++i) {
            key[i] = INT_MAX;
            parent[i] = -1;
            mstSet[i] = false;
        }

        key[0] = 0;

        for (int count = 0; count < V - 1; ++count) {
            int u = minKey(key, mstSet);
            mstSet[u] = true;

            for (int v = 0; v < V; ++v) {
                if (graph[u][v] > 0 && !mstSet[v] && key[v] > graph[u][v]) {
                    key[v] = graph[u][v];
                    parent[v] = u;
                }
            }
        }

        printMST(parent);

        delete[] key;
        delete[] parent;
        delete[] mstSet;
    }
};
int main() {
    Graph g(5);
    g.graph = new int* [5] {
        new int[5] {0, 2, 0, 6, 0},
        new int[5] {2, 0, 3, 8, 5},
        new int[5] {0, 3, 0, 0, 7},
        new int[5] {6, 8, 0, 0, 9},
        new int[5] {0, 5, 7, 9, 0}
    };

    g.primMST();

    for (int i = 0; i < 5; ++i) {
        delete[] g.graph[i];
    }
    delete[] g.graph;

    return 0;
}
