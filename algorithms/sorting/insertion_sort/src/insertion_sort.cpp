#include "../inc/insertion_sort.h"

#include <algorithm>
#include <iostream>


/**
 * Sort a given vector of integers in-place using the insertion sort 
 * algorithm.
 * 
 * @param[in,out] array     Vector to be sorted
 */
void insertion_sort(std::vector<int>& array) {
    for (int i = 1; i < (int) array.size(); ++i) {
        int key = array[i];

        // Iterate through array[1, i - 1] backwards and insert
        // in front of first element that is smaller
        int j;
        for (j = i - 1; j >= 0; j--) {
            if ((!DESC && array[j] > key) || (DESC && array[j] < key)) {
                // Shift greater element to the right
                array[j + 1] = array[j];
            } else {
                break;
            }
        }

        // array[j] is the first element smaller than key or
        // j+1 is beginning of the array and key is the smalles 
        // element in the array
        array[j + 1] = key;
    }
}


/*
 * Print an array to stdout.
 */
void _print_vector(const std::vector<int>& array) {
    for (const int &value : array) {
        std::cout << value << ", "; 
    }
    std::cout << std::endl;
}
