#include "graph.hpp"

// EDGE RELATED METHODS

/**
* EDGE NON-DEFAULT CONSTRUCTOR
*
* @param source         The source vertex index.
* @param destination    The destination vertex index.
* @param weight         The weight of the edge.
*/
Edge::Edge(int source, int destination, int weight) {
    this->source = source;
    this->destination = destination;
    this->weight = weight;
}

/**
* CREATE EDGE ARRAY
* Turns an adjacency matrix into an array which contains the edges of the
* graph.
*
* @param adjMatrix  The adjacency matrix.
* @param matrixSize The N size of a NxN matrix.
* @return           The array of edges.
*/
std::vector<Edge*> Edge::createEdgeArray(std::vector<int*> &adjMatrix,
                                         int matrixSize) {
    std::vector<Edge*> edgeArray;
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            if (adjMatrix[i][j] != 0) {
                Edge* edge = new Edge(i, j, adjMatrix[i][j]);
                edgeArray.push_back(edge);
            }
        }
    }
    return edgeArray;
}

// GRAPH RELATED METHODS

/**
* GRAPH NON-DEFAULT CONSTRUCTOR
*
* @param vertices   The number of vertices on the graph.
* @param edges      The array of edges that compose the graph.
*/
Graph::Graph(int vertices,
             std::vector<Edge*> &edges,
             std::vector<int*> &adjMatrix) {
    this->vertices = vertices;
    this->edges = edges.size();
    this->edgeData = edges;
    this->adjMatrix = adjMatrix;
}
