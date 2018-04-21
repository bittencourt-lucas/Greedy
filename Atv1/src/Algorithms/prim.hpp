/**
* Prim's Minimum Spanning Tree algorithm implemented by Lucas Bittencourt.
*
* Prim's Minimum Spanning Tree is a Greedy algorithm. This implementation uses
* the adjacency matrix of the graph to calculate the minimum spanning tree.
* This implies that the complexity of the code is O(V²), but it's easier to
* understand the concepts.
*/

#ifndef PRIM_HPP_
#define PRIM_HPP_

#include <iostream>
#include <limits>
#include "../Graph/graph.hpp"

class Prim {

public:
    // Methods
    void primMST(Graph*);

private:
    // Members
    int vertices;
    // Methods
    int minElement(int*, bool*);

};

#endif /* PRIM_HPP_ */
