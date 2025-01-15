#include "../include/handleProblem2.h"
#include <climits>
#include <iostream>
#include "../include/inputValidation.h"
using namespace std;

int V; // Number of vertices in the graph

int minDistance(const int dist[], const bool sptSet[])
{

    // Initialize min value
    int min = INT_MAX, min_index = 0;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// A utility function to print the constructed distance
// array
void printSolution(int dist[])
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void dijkstra(const vector<vector<int>>& graph, const int src)
{
    int dist[V]; // The output array.  dist[i] will hold the
                 // shortest
    // distance from src to i

    bool sptSet[V]; // sptSet[i] will be true if vertex i is
                    // included in shortest
    // path tree or shortest distance from src to i is
    // finalized

    // Initialize all distances as INFINITE and stpSet[] as
    // false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed. u is always equal to
        // src in the first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the
        // picked vertex.
        for (int v = 0; v < V; v++)

            // Update dist[v] only if is not in sptSet,
            // there is an edge from u to v, and total
            // weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v]
                && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // print the constructed distance array
    printSolution(dist);
}

void handleProblem2() {
    int option = 0;
    std::cout << "\nDijkstra's algorithm" << std::endl;
    do {
        // Get the number of vertices from the user
        V = handleUserInput<int>("Enter the number of vertices: ",
                                    [](int x) { return x > 0; },
                                    "Invalid input! Please enter a positive number: ");

        vector graph(V, vector<int>(V, 0));

        // Get the adjacency matrix from the user
        std::cout << "Enter the adjacency matrix:" << std::endl;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                graph[i][j] = handleUserInput<int>("",
                                                    [](int x) { return x >= 0; },
                                                    "Invalid input! Please enter a positive number: ");
            }
        }
        // Get the source vertex from the user
        int src = handleUserInput<int>("Enter the source vertex: ",
                                       [](int x) { return x >= 0 && x < V; },
                                       "Invalid input! Please enter a number between 0 and " + std::to_string(V - 1) + ": ");

        dijkstra(graph,src);

        // Ask the user if they want to run the algorithm again
        std::cout<< "\n1. Run the algorithm again" << std::endl;
        std::cout << "0. Back to main menu" << std::endl;
        option = handleUserInput<int>("Choose an option: ",
            [](int x) { return x >= 0 && x <= 1; },
            "Invalid option! Please enter 0 or 1: ");

    } while (option == 1);
}