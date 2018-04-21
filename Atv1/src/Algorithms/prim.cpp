#include "prim.hpp"

/**
* PRIM'S MINIMUM SPANNING TREE
* Applies Prim's algorithm to create a minimum spanning tree using the
* adjacency matrix of the graph.
*
* @param graph      The NxN graph.
*/
void Prim::primMST(Graph* graph) {
    this->vertices = graph->getVertices();
    int parent[this->vertices];
    int element[this->vertices];
    bool setMST[this->vertices];
    // All elements are initialized with MAX_INT.
    for (int i = 0; i < this->vertices; i++){
        element[i] = std::numeric_limits<int>::max();
        setMST[i] = false;
    }
    // The first edge is always included on the minimum spanning tree.
    element[0] = 0;
    parent[0] = -1;
    // The smallest element (weight) that is not part of the minimum spanning
    // tree is picked and added. The element value and parent index of the
    // adjacent edge are update.
    for (int count = 0; count < this->vertices - 1; count++) {
        int u = minElement(element, setMST);
        setMST[u] = true;
        for (int v = 0; v < this->vertices; v++) {
            int graphKey = graph->adjMatrix[u][v];
            if (graphKey && setMST[v] == false && graphKey < element[v]) {
                parent[v] = u;
                element[v] = graphKey;
            }
        }
    }
    // Prints the minimum spanning tree.
    std::cout << "Prim's Minimum Spanning Tree" << std::endl;
    for (int i = 1; i < this->vertices; i++) {
        std::cout << parent[i] << " -- " << i <<
        " Weight: " << graph->adjMatrix[i][parent[i]] << std::endl;
    }
}

/**
* MIN ELEMENT
* Finds the edge with the smallest weight from a set that hasn't been added to
* the minimum spanning tree.
*
* @param element[]  The elements inside a set of the graph.
* @param setMST[]   The set of edges that compose the minimum spanning tree.
* @return           The index of the smallest weight.
*/
int Prim::minElement(int* element, bool* setMST) {
    int min = std::numeric_limits<int>::max();
    int minIndex;
    for (int v = 0; v < this->vertices; v++)
        if (setMST[v] == false && element[v] < min) {
            min = element[v];
            minIndex = v;
        }
    return minIndex;
}
