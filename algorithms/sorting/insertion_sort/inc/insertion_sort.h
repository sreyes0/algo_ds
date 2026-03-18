#pragma once

#include <vector>

/**
 * Sort a given vector of integers in-place using the insertion sort 
 * algorithm.
 * 
 * @param[in,out] array     Vector to be sorted
 */
void insertion_sort(std::vector<int>& array);


/**
 * Take an array and compare the result of our implementation of
 * the sorting algorithm with the output of the standard library
 * version.
 *
 * @param[in.out] array     Vector to test 
 * @return                  True if result of our implementation matches
 *                          the std solution.
 */
bool test_insertion_sort(std::vector<int>& array);


/*
 * Print an array to stdout.
 * 
 * @param[in] array         Vector to print to stdout
 */
void _print_vector(const std::vector<int>& array);
