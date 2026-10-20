#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// -------------------------
// Structure for an Edge
// -------------------------

struct Edge
{
    int source;
    int destination;
    int weight;
};

// -------------------------
// Find Parent
// -------------------------

int findParent(vector<int> &parent, int vertex)
{
    if (parent[vertex] == vertex)
        return vertex;

    return parent[vertex] = findParent(parent, parent[vertex]);
}

// -------------------------
// Kruskal's Algorithm
// -------------------------

void kruskalMST(vector<Edge> edges, int vertices)
{
    // Sort edges according to weight
    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b)
         {
             return a.weight < b.weight;
         });

    vector<int> parent(vertices);

    // Initially, every vertex is its own parent
    for (int i = 0; i < vertices; i++)
    {
        parent[i] = i;
    }

    int totalCost = 0;
    int edgesSelected = 0;

    cout << "\nMinimum Spanning Tree:\n";
    cout << "Edge\tWeight\n";

    // Check edges one by one
    for (Edge edge : edges)
    {
        int sourceParent = findParent(parent, edge.source);
        int destinationParent = findParent(parent, edge.destination);

        // Select edge only if it does not form a cycle
        if (sourceParent != destinationParent)
        {
            cout << edge.source
                 << " - "
                 << edge.destination
                 << "\t"
                 << edge.weight
                 << endl;

            totalCost += edge.weight;

            parent[sourceParent] = destinationParent;

            edgesSelected++;

            // MST needs V - 1 edges
            if (edgesSelected == vertices - 1)
                break;
        }
    }

    cout << "\nTotal MST Cost = " << totalCost << endl;
}

// -------------------------
// Main Function
// -------------------------

int main()
{
    int vertices, edgesCount;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter number of edges: ";
    cin >> edgesCount;

    vector<Edge> edges(edgesCount);

    cout << "\nEnter edges (source destination weight):\n";

    for (int i = 0; i < edgesCount; i++)
    {
        cin >> edges[i].source
            >> edges[i].destination
            >> edges[i].weight;
    }

    kruskalMST(edges, vertices);

    return 0;
}
