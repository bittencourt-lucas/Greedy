/**
* Dijkstra's Shortest Path algorithm implemented by Lucas Bittencourt.
*
* Dijkstra's Shortest Path is a Greedy algorithm. This implementation uses the
* adjacency matrix of the graph to calculate the shortest path. It implies that
* the complexity of the code is O(V²), but it's easier to understand the
* concepts.
*/

#ifndef DIJKSTRA_HPP_
#define DIJKSTRA_HPP_

#include <iostream>
#include <limits>
#include "../Graph/graph.hpp"

class Dijkstra {

public:
    // Methods
    void dijkstraAdjMatrix(Graph*, int);

private:
    // Members
    int vertices;
    // Methods
    int minDistance(int*, bool*);

};

#endif /* DIJKSTRA_HPP_ */
