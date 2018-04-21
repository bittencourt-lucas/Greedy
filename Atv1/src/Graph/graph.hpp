/**
* Graph data structure implemented by Lucas Bittencourt.
*
* A graph contains N nodes that can connect to one another with no particular
* order. Graphs contain edges and vertices.
*/

#ifndef GRAPH_HPP_
#define GRAPH_HPP_

#include <vector>

class Edge {
public:
    // Constructors
    Edge(int, int, int);
    // Methods
    static std::vector<Edge*> createEdgeArray(std::vector<int*>&, int);
    int getSource() { return this->source; }
    int getDestination() { return this->destination; }
    int getWeight() { return this->weight; }

private:
    // Members
    int source;
    int destination;
    int weight;
};

class Graph {

public:
    // Constructors
    Graph(int, std::vector<Edge*>&, std::vector<int*>&);
    // Members
    std::vector<Edge*> edgeData;
    std::vector<int*> adjMatrix;
    // Methods
    int getEdges() { return this->edges; }
    int getVertices() { return this->vertices; }

private:
    // Members
    int edges;
    int vertices;

};

#endif /* GRAPH_HPP_ */
