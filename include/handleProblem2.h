#ifndef HANDLEPROBLEM2_H
#define HANDLEPROBLEM2_H

#include <vector>
// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in shortest path tree
int minDistance(const int dist[], const bool sptSet[]);

// A utility function to print the constructed distance
// array
void printSolution(int dist[]);

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void dijkstra(const std::vector<std::vector<int>>&graph, int src);

void handleProblem2();

#endif //HANDLEPROBLEM2_H
