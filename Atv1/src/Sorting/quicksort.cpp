#include "quicksort.hpp"

/**
* SORT
* This is the method called by the user.
*
* @param array      An n-sized array to be sorted.
*/
void Quicksort::sort(std::vector<Edge*>& array) {
    quickSort(array, 0, array.size() - 1);
}

/**
* QUICKSORT
* Actual implementation of the QuickSort algorithm. There are different ways
* the QuickSort algorithm can pick a pivot to work around. This implementation
* always pick the last element as pivot.
*
* @param array      An n-sized array to be sorted.
* @param low        Starting index of the array.
* @param high       Ending index of the array.
*/
void Quicksort::quickSort(std::vector<Edge*>& array, int low, int high) {
    if (low < high) {
        int partIndex = partition(array, low, high);
        quickSort(array, low, partIndex - 1);
        quickSort(array, partIndex + 1, high);
    }
}

/**
* PARTITION
* This is the core of the QuickSort algorithm. It takes the last element as a
* pivot, places the pivot element in it's correct position in sorted array,
* and then places all elements smaller than the pivot to the left and all
* elements greater than the pivot to the right of it.
*
* @param array      An n-sized array to be sorted.
* @param low        Starting index of the array.
* @param high       Ending index of the array.
* @return           The index of the pivot.
*/
int Quicksort::partition(std::vector<Edge*>& array, int low, int high) {
    // The pivot is always the last element of the array.
    int pivot = array[high]->getWeight();

    // This is the index of a smaller element.
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        // Checks if the current element is smaller or equal to the pivot. If
        // true, increments the index of a smaller element.
        if (array[j]->getWeight() <= pivot) {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return (i + 1);
}

void Quicksort::swap(Edge*& a, Edge*& b) {
    Edge* tmp = a;
    a = b;
    b = tmp;
}
