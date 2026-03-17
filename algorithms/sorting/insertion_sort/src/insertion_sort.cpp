#include <algorithm>
#include <iostream>
#include <vector>


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
            if (array[j] > key) {
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


/**
 * Take an array and compare the result of our implementation of
 * the sorting algorithm with the output of the standard library
 * version.
 *
 * @param[in.out] array     Vector to test 
 * @return                  True if result of our implementation matches
 *                          the std solution.
 */
bool test_insertion_sort(std::vector<int>& array) {
    // Output comparison
    std::vector<int> sorted_array = array;
    std::sort(sorted_array.begin(), sorted_array.end());

    // Use our implementation of algorithm
    insertion_sort(array);

    // Compare
    return std::equal(array.begin(), array.end(), sorted_array.begin());
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


int main() {
    // Input vector
    std::vector<int> array = {44, 5, 37, 1, 25, -49, -18, -24, 48, -21, -34,
                              12, -43, -16, -22, 36, 26, -33, 6, -32};
    std::vector<int> input = array;

    if (test_insertion_sort(array)) {
        std::cout << "Insertion sort successful!" << std::endl;
    } else {
        std::cout << "Insertion sort failed!" << std::endl;

        std::cout << "Input: ";
        _print_vector(input);

        std::cout << "Output: ";
        _print_vector(array);
    }
}





