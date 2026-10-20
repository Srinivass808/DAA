#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// -------------------------
// Prim's Algorithm
// -------------------------

void primMST(vector<vector<int>> graph, int vertices)
{
    vector<int> parent(vertices, -1);
    vector<int> key(vertices, INT_MAX);
    vector<bool> inMST(vertices, false);

    // Start from vertex 0
    key[0] = 0;

    // Select vertices one by one
    for (int count = 0; count < vertices - 1; count++)
    {
        int minimum = INT_MAX;
        int currentVertex = -1;

        // Find the vertex with minimum key value
        for (int vertex = 0; vertex < vertices; vertex++)
        {
            if (!inMST[vertex] && key[vertex] < minimum)
            {
                minimum = key[vertex];
                currentVertex = vertex;
            }
        }

        // Include selected vertex in MST
        inMST[currentVertex] = true;

        // Update adjacent vertices
        for (int vertex = 0; vertex < vertices; vertex++)
        {
            if (graph[currentVertex][vertex] != 0 &&
                !inMST[vertex] &&
                graph[currentVertex][vertex] < key[vertex])
            {
                key[vertex] = graph[currentVertex][vertex];
                parent[vertex] = currentVertex;
            }
        }
    }

    // -------------------------
    // Display MST
    // -------------------------

    int totalCost = 0;

    cout << "\nMinimum Spanning Tree:\n";
    cout << "Edge\tWeight\n";

    for (int vertex = 1; vertex < vertices; vertex++)
    {
        cout << parent[vertex]
             << " - "
             << vertex
             << "\t"
             << graph[vertex][parent[vertex]]
             << endl;

        totalCost += graph[vertex][parent[vertex]];
    }

    cout << "\nTotal MST Cost = " << totalCost << endl;
}

// -------------------------
// Main Function
// -------------------------

int main()
{
    int vertices;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    vector<vector<int>> graph(vertices, vector<int>(vertices));

    cout << "\nEnter the adjacency matrix (" 
         << vertices << " x " << vertices << "):\n";

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cin >> graph[i][j];
        }
    }

    primMST(graph, vertices);

    return 0;
}
