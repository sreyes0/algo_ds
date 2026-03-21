#pragma once

#include <vector>
#define DESC 0

/**
 * Sort a given vector of integers in-place using the merge sort 
 * algorithm.
 * 
 * @param[in,out] array     Vector to be sorted
 */
void merge_sort(std::vector<int>& array);

/**
 * Merge two sorted subarrays into a sorted combined array.
 *
 * @param[in] array1        Sorted subarray
 * @param[in] array2        Sorted subarray
 * return                   Sorted merged array
 */
std::vector<int> merge(const std::vector<int> &array1, 
        const std::vector<int> &array2);

