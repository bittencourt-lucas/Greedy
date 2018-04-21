/**
* Kruskal's Minimum Spanning Tree algorithm implemented by Lucas Bittencourt.
*
* Kruskal's Minimum Spanning Tree is a Greedy algorithm. A minimum spanning
* tree for a weighted, connected and undirected graph is a spanning tree
* that weights less or equal than the weight of any other spanning tree.
*/

#ifndef KRUSKAL_HPP_
#define KRUSKAL_HPP_

#include <iostream>
#include <vector>
#include "../Graph/graph.hpp"
#include "../Sorting/quicksort.hpp"

typedef struct Subset {
    int parent;
    int rank;
} Subset;

class Kruskal {

public:
    // Methods
    void kruskalMST(Graph*);

private:
    // Methods
    int Find(Subset*, int);
    void Union(Subset*, int, int);

};

#endif /* KRUSKAL_HPP_ */
