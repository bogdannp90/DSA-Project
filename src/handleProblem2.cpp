#include "../include/handleProblem2.h"
#include <climits>
#include <iostream>
#include "../include/inputValidation.h"

int V;

/**
 * @brief Finds the vertex with the minimum distance value, from the set of vertices
 * not yet included in the shortest path tree.
 *
 * @param dist Array holding the shortest distance from the source to each vertex.
 * @param sptSet Array indicating whether a vertex is included in the shortest path tree.
 * @return Index of the vertex with the minimum distance value.
 */
int minDistance(const std::vector<int> &dist, const std::vector<bool> &sptSet) {
    int min = INT_MAX, min_index = 0;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

/**
 * @brief Prints the path from the source to a given vertex.
 *
 * @param parent Array holding the vertex that precedes each vertex in the shortest path.
 * @param j The vertex to print the path for.
 */
void printPath(const std::vector<int> &parent, int j) {
    if (parent[j] == -1) {
        std::cout << j << " ";
        return;
    }
    printPath(parent, parent[j]);
    std::cout << j << " ";
}

/**
 * @brief Prints the constructed distance array and the paths from the source to each vertex.
 *
 * @param dist Array holding the shortest distance from the source to each vertex.
 * @param parent Array holding the vertex that precedes each vertex in the shortest path.
 */
void printSolution(const std::vector<int> &dist, const std::vector<int> &parent) {
    std::cout << "\nVertex\tDistance\tPath" << std::endl;
    for (int i = 0; i < dist.size(); i++) {
        std::cout << i << "\t" << dist[i] << "\t\t";
        printPath(parent, i);
        std::cout << std::endl;
    }
}

/**
 * @brief Implements Dijkstra's single source shortest path algorithm for a graph
 * represented using adjacency matrix representation.
 *
 * @param graph 2D vector representing the adjacency matrix of the graph.
 * @param src Source vertex.
 */
void dijkstra(const std::vector<std::vector<int> > &graph, const int src) {
    std::vector<int> dist(V, INT_MAX); // The output array. dist[i] will hold the shortest distance from src to i
    std::vector<bool> sptSet(V, false); // sptSet[i] will be true if vertex i is included in shortest path tree
    std::vector<int> parent(V, -1); // parent[i] will hold the vertex that precedes i in the shortest path

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex
        // Update value of parent vertex
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
    }

    // Print the constructed distance array
    printSolution(dist, parent);
}

/**
 * @brief Handles the user interaction for solving Problem 2 using Dijkstra's algorithm.
 * Prompts the user for the number of vertices, the adjacency matrix, and the source vertex.
 * Runs the Dijkstra's algorithm and displays the results.
 */
void handleProblem2() {
    int option = 0;
    std::cout << "\nDijkstra's algorithm" << std::endl;
    do {
        // Get the number of vertices from the user
        V = handleUserInput<int>("Enter the number of vertices: ",
                                 [](int x) { return x > 0; },
                                 "Invalid input! Please enter a positive number: ");

        std::vector graph(V, std::vector<int>(V, 0));

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
                                       "Invalid input! Please enter a number between 0 and " + std::to_string(V - 1) +
                                       ": ");

        dijkstra(graph, src);

        // Ask the user if they want to run the algorithm again
        std::cout << "\n1. Run the algorithm again" << std::endl;
        std::cout << "0. Back to main menu" << std::endl;
        option = handleUserInput<int>("Choose an option: ",
                                      [](int x) { return x >= 0 && x <= 1; },
                                      "Invalid option! Please enter 0 or 1: ");
    } while (option == 1);
}