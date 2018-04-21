/**
* QuickSort algorithm implemented by Lucas Bittencourt.
*
* QuickSort is a Divide and Conquer algorithm. It picks an element as pivot
* and partitions the given array around the picked pivot.
*/

#ifndef QUICKSORT_HPP_
#define QUICKSORT_HPP_

#include <vector>
#include "../Graph/graph.hpp"

class Quicksort {

public:
    // Methods
    void sort(std::vector<Edge*>&);

private:
    // Methods
    void quickSort(std::vector<Edge*>&, int, int);
    int partition(std::vector<Edge*>&, int, int);
    void swap(Edge*&, Edge*&);

};

#endif /* QUICKSORT_HPP_ */
