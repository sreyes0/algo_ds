#include "../inc/merge_sort.h"

#include <algorithm>
#include <iostream>

#include <catch2/catch_test_macros.hpp>

#define CONFIG_CATCH_MAIN

TEST_CASE( "Test merge sort algorithm", "[merge_sort]" ) {
    // Input vector
    std::vector<int> array = {44, 5, 37, 1, 25, -49, -18, -24, 48, -21, -34,
                              12, -43, -16, -22, 36, 26, -33, 6, -32};
    std::vector<int> input = array;

    // array = {};
    // array = { 10, 10, 10, 10, 10, 10, 10, 9, 10, 10, 10, 10, 10};

    // Sort target
    std::sort(input.begin(), input.end());

    // Our solution
    merge_sort(array);

    CHECK( std::equal(array.begin(), array.end(), input.begin()) );
}


TEST_CASE( "Test merge procedure", "[merge]" ) {
    std::vector<int> array1 = {-22, -7, 0, 1, 6, 10, 24};
    std::vector<int> array2 = {-12, -1, 10, 16, 32};

    // Proprietary solution
    std::vector<int> result = merge(array1, array2);

    // STL solution
    std::vector<int> stl_result = array1;
    stl_result.insert(stl_result.end(), array2.begin(), array2.end());
    std::sort(stl_result.begin(), stl_result.end());

    CHECK( std::equal(stl_result.begin(), stl_result.end(), result.begin()) );
}
