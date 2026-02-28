#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class DSU {
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size.assign(n, 1);
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    void unionBySize(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);

        if (root_u != root_v) {
            if (size[root_u] < size[root_v])
                swap(root_u, root_v);

            parent[root_v] = root_u;
            size[root_u] += size[root_v];
        }
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    DSU dsu(V);

    bool cycleFound = false;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        if (dsu.find(u) == dsu.find(v)) {
            cout << "Cycle detected when adding edge "
                 << u << " - " << v << endl;
            cycleFound = true;
        } else {
            dsu.unionBySize(u, v);
        }
    }

    if (!cycleFound) {
        cout << "No cycle found in the graph.\n";
    }

    return 0;
}

// INPUT

// Enter number of vertices: 5
// Enter number of edges: 5

// Enter edges:
// 0 1
// 1 2
// 2 3
// 3 4
// 1 3




// OUTPUT

// Cycle detected when adding edge 1 - 3