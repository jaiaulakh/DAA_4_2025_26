#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Graph {
    int vertices;
    vector<vector<pair<int, int>>> adjacencyList;
public:
    Graph(int v) {
        vertices = v;
        adjacencyList.resize(vertices);
    }

    void addEdge(int u, int v, int w) {
        adjacencyList[u].push_back({v, w});
        adjacencyList[v].push_back({u, w});
    }

    void primMST() {
        vector<int> minCost(vertices, INT_MAX);
        vector<int> parent(vertices, -1);
        vector<bool> visited(vertices, false);

        priority_queue<pair<int, int>, 
                       vector<pair<int, int>>, 
                       greater<pair<int, int>>> pq;

        pq.push({0, 0});
        minCost[0] = 0;

        while (!pq.empty()) {
            int node = pq.top().second;
            pq.pop();

            if (visited[node])
                continue;

            visited[node] = true;

            for (auto edge : adjacencyList[node]) {
                int next = edge.first;
                int weight = edge.second;

                if (!visited[next] && weight < minCost[next]) {
                    minCost[next] = weight;
                    parent[next] = node;
                    pq.push({minCost[next], next});
                }
            }
        }

        int totalCost = 0;
        cout << "\nEdges in MST:\n";
        cout << "Parent - Node  Weight\n";
        for (int i = 1; i < vertices; i++) {
            cout << parent[i] << " - " << i 
                 << "       " << minCost[i] << endl;
            totalCost += minCost[i];
        }

        cout << "\nTotal Cost of MST = " << totalCost << endl;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;
    Graph g(V);
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    g.primMST();
    return 0;
}



// I/P
// Enter number of vertices: 5
// Enter number of edges: 7

// Enter edges:
// 0 1 2
// 0 3 6
// 1 2 3
// 1 3 8
// 1 4 5
// 2 4 7
// 3 4 9







// o/p
// Total Cost of MST = 16