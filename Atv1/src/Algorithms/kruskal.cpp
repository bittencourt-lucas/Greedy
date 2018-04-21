#include "kruskal.hpp"

/**
* KRUSKAL'S MINIMUM SPANNING TREE
* Applies Kruskal's algorithm to create a minimum spanning tree.
*
* @param graph      The NxN graph.
*/
void Kruskal::kruskalMST(Graph* graph) {
    int vertices = graph->getVertices();
    Edge* MST[vertices];
    int e = 0;
    int i = 0;
    // Sorts the edges in a non-decreasing order of their weight.
    Quicksort quickSort;
    quickSort.sort(graph->edgeData);
    Subset* subsets = new Subset[vertices];
    for (int v = 0; v < vertices; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    // Picks the smallest edge and increments the index for the next iteration.
    while (e < vertices - 1) {
        Edge* nEdge = graph->edgeData[i++];
        int x = Find(subsets, nEdge->getSource());
        int y = Find(subsets, nEdge->getDestination());

        if (x != y) {
            MST[e++] = nEdge;
            Union(subsets, x, y);
        }
    }
    // Prints the minimum spanning tree.
    std::cout << "Kruskal's Minimum Spanning Tree" << std::endl;
    for (int i = 0; i < e; i++)
        std::cout << MST[i]->getSource() << " -- " <<
        MST[i]->getDestination() << " Weight: " << MST[i]->getWeight() <<
        std::endl;
}

/**
* FIND
* Finds a set of an element.
*
* @param subsets[]  A set of the graph.
* @param index      An element.
*/
int Kruskal::Find(Subset* subsets, int index) {
    if (subsets[index].parent != index)
        subsets[index].parent = Find(subsets, subsets[index].parent);
    return subsets[index].parent;
}

/**
* UNION
* The union of two sets A and B using union by rank.
*
* @param subsets[]  A set of the graph.
* @param setA       A set.
* @param setB       A set.
*/
void Kruskal::Union(Subset* subsets, int setA, int setB) {
    int rootA = Find(subsets, setA);
    int rootB = Find(subsets, setB);
    // Unites a tree with smaller rank to a tree of higher rank.
    if (subsets[rootA].rank < subsets[rootB].rank)
        subsets[rootA].parent = rootB;
    else if (subsets[rootA].rank > subsets[rootB].rank)
        subsets[rootB].parent = rootA;
    // If the ranks are the same, than turns one into a root and increments
    // it's rank.
    else {
        subsets[rootB].parent = rootA;
        subsets[rootA].rank++;
    }
}
