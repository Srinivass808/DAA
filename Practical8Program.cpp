#include <iostream>
#include <vector>
#include <queue>
#include <chrono>

class Graph {
private:
    int V;
    std::vector<std::vector<int>> adj;

    // Moved to private: Helper functions shouldn't be exposed to the user[cite: 1]
    void DFSUtil(int v, std::vector<bool> &visited) {
        visited[v] = true;
        std::cout << v << " ";

        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);   // Remove this line for directed graph[cite: 1]
    }

    void DFS(int start) {
        std::vector<bool> visited(V, false);
        DFSUtil(start, visited);
    }

    void BFS(int start) {
        std::vector<bool> visited(V, false);
        std::queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            std::cout << node << " ";

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};

int main() {
    int V, E;

    std::cout << "Enter number of vertices: ";
    std::cin >> V;

    Graph g(V);

    std::cout << "Enter number of edges: ";
    std::cin >> E;

    std::cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        std::cin >> u >> v;
        g.addEdge(u, v);
    }

    int start;
    std::cout << "Enter starting vertex: ";
    std::cin >> start;

    // DFS Time Analysis[cite: 1]
    auto startDFS = std::chrono::high_resolution_clock::now();
    std::cout << "\nDFS Traversal: ";
    g.DFS(start);
    auto endDFS = std::chrono::high_resolution_clock::now();

    auto dfsTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endDFS - startDFS);

    // BFS Time Analysis[cite: 1]
    auto startBFS = std::chrono::high_resolution_clock::now();
    std::cout << "\n\nBFS Traversal: ";
    g.BFS(start);
    auto endBFS = std::chrono::high_resolution_clock::now();

    auto bfsTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endBFS - startBFS);

    std::cout << "\n\n--- Execution Time ---\n";
    std::cout << "DFS: " << dfsTime.count() << " ns\n";
    std::cout << "BFS: " << bfsTime.count() << " ns\n";

    return 0;
}
