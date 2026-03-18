#pragma once

#include <vector>

#define DESC 0

/**
 * Sort a given vector of integers in-place using the insertion sort 
 * algorithm.
 * 
 * @param[in,out] array     Vector to be sorted
 */
void insertion_sort(std::vector<int>& array);


/*
 * Print an array to stdout.
 * 
 * @param[in] array         Vector to print to stdout
 */
void _print_vector(const std::vector<int>& array);
