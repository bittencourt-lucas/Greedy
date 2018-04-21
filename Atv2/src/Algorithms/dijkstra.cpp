#include "dijkstra.hpp"

/**
* DIJKSTRA'S SHORTEST PATH USING ADJACENCY MATRIX
* Dijkstra uses the same algorithm as Prim's Minimum Spanning Tree algorithm,
* but instead it calculates the shortest path between a source and the other
* nodes.
*
* @param graph      The NxN graph.
* @param source     The node that serves as the source of the path.
*/
void Dijkstra::dijkstraAdjMatrix(Graph* graph, int source) {
    this->vertices = graph->getVertices();
    int distance[this->vertices];
    bool setSP[this->vertices];
    // All elements are initialized with MAX_INT.
    for (int i = 0; i < this->vertices; i++) {
        distance[i] = std::numeric_limits<int>::max();
        setSP[i] = false;
    }
    // The distance from the source to itself is zero.
    distance[source] = 0;
    // The smallest distance that is not part of the shortest path
    // is picked and added. The element value and parent index of the
    // adjacent edge are update.
    for (int count = 0; count < this->vertices - 1; count++) {
        int u = minDistance(distance, setSP);
        setSP[u] = true;
        for (int v = 0; v < this->vertices; v++) {
            int graphDistance = graph->adjMatrix[u][v];
            if (!setSP[v] && graphDistance &&
                distance[u] != std::numeric_limits<int>::max()
                && distance[u] + graphDistance < distance[v])
                distance[v] = distance[u] + graphDistance;
        }
    }
    // Prints the shortest path from the source to the other edges.
    std::cout << "Dijsktra's Shortest Path" << std::endl;
    for (int i = 0; i < this->vertices; i++) {
        std::cout << source << " -- " << i <<
        " Distance: " << distance[i] << std::endl;
    }

}

/**
* MIN DISTANCE
* Finds the edge with the smallest distance from a set that hasn't been added
* to the shortest path.
*
* @param distance[] The distance between the edges of a graph.
* @param setSP[]    The set of edges that compose the shortest path.
* @return           The index of the shortest distance.
*/
int Dijkstra::minDistance(int* distance, bool* setSP) {
    int min = std::numeric_limits<int>::max();
    int minIndex;
    for (int v = 0; v < this->vertices; v++)
        if (setSP[v] == false && distance[v] < min) {
            min = distance[v];
            minIndex = v;
        }
    return minIndex;
}
