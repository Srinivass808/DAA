#include <iostream>
#include <vector>

using namespace std;

// -------------------------
// Floyd-Warshall Algorithm
// -------------------------

void floydWarshall(vector<vector<int>> graph, int vertices)
{
    // Update shortest distances using each vertex as an intermediate vertex
    for (int k = 0; k < vertices; k++)
    {
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                if (graph[i][k] != 999 && graph[k][j] != 999)
                {
                    if (graph[i][k] + graph[k][j] < graph[i][j])
                    {
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                }
            }
        }
    }

    // -------------------------
    // Display Shortest Distances
    // -------------------------

    cout << "\nShortest Distance Matrix:\n";

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (graph[i][j] == 999)
                cout << "INF\t";
            else
                cout << graph[i][j] << "\t";
        }

        cout << endl;
    }
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

    cout << "Enter 999 if there is no direct edge.\n";

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cin >> graph[i][j];
        }
    }

    floydWarshall(graph, vertices);

    return 0;
}
