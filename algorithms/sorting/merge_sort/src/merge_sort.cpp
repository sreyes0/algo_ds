#include "../inc/merge_sort.h"

#include <cassert>
#include <limits>


void merge_sort(std::vector<int> &array) 
{
    // End of recursion
    if (array.size() <= 1) {
        return;
    }

    // Split array
    int mid_index = array.size() / 2;
    std::vector<int>::iterator middle = array.begin() + mid_index;

    std::vector<int> array1(array.begin(), middle);
    std::vector<int> array2(middle, array.end());

    assert(array.size() == array1.size() + array2.size());

    // Recursive sort for each half
    merge_sort(array1);
    merge_sort(array2);

    // Merge sorted results
    array = merge(array1, array2);
}

std::vector<int> merge(std::vector<int> array1, std::vector<int> array2)
{
    int total_size = array1.size() + array2.size();
    std::vector<int> array;
    array.reserve(total_size);  // Reserve allocates memory but does not
                                // instantiate anything

    // Append MAX_INT to end of both arrays so we don't have to 
    // check for array limits in the loop
    array1.push_back(std::numeric_limits<int>::max());
    array2.push_back(std::numeric_limits<int>::max());

    int index1 = 0, index2 = 0;
    for (int i = 0; i < total_size; ++i) {
        // Append smaller of the two elements pointed at
        if (array1[index1] < array2[index2]) {
            array.push_back(array1[index1++]);
        } else {
            array.push_back(array2[index2++]);
        }
    }

    return array;
}
