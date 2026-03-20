#include "../inc/merge_sort.h"

#include <algorithm>
#include <vector>

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
    if (DESC) {
        std::sort(input.begin(), input.end(), std::greater<>());
    } else {
        std::sort(input.begin(), input.end());
    }

    // Our solution
    merge_sort(array);

    REQUIRE( std::equal(array.begin(), array.end(), input.begin()) );
}

