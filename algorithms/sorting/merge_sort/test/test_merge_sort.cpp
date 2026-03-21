#include "../inc/merge_sort.h"

#include <algorithm>
#include <iostream>
#include <limits>

#include <catch2/catch_test_macros.hpp>

#define CONFIG_CATCH_MAIN

void test_merge_sort_helper(std::string section_name, std::vector<int> &array) {
    // Every test in own section otherwise failures just point
    // to the helper function and not which instance of the call
    // exactly
    SECTION(section_name) {
        try {
            // STL solution
            std::vector<int> stl_result = array;
            std::sort(stl_result.begin(), stl_result.end());

            // Propietary solution
            merge_sort(array);

            CHECK( std::equal(array.begin(), array.end(), stl_result.begin()) );
        } catch (const std::exception &e) {
            FAIL(e.what());
        }
    }
}

TEST_CASE( "Test merge sort algorithm", "[merge_sort]" ) {
    // Input vector
    std::vector<int> array = {};
    test_merge_sort_helper("Empty array", array);

    array = {1};
    test_merge_sort_helper("Single element array", array);

    array = {1, -10};
    test_merge_sort_helper("Two-element array", array);

    array = { 1, 40, -70, std::numeric_limits<int>::max(), 32, -20 };
    test_merge_sort_helper("Array containing MAX_INT", array);

    array = {44, 5, 37, 1, 25, -49, -18, -24, 48, -21, -34,
             12, -43, -16, -22, 36, 26, -33, 6, -32};
    test_merge_sort_helper("Normal populated array", array);
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
