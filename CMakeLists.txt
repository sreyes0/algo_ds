cmake_minimum_required(VERSION 4.2)

project("Algorithms and Data Structures")

# Create a target
add_executable(insertion_sort)

# Associate properties with target
# Note: paths are either absolute or relative to CMAKE_CURRENT_SOURCE_DIR
target_sources(insertion_sort
  PRIVATE   # Scope (nothing depends on the source file -> PRIVATE)
    algorithms/sorting/insertion_sort/src/insertion_sort.cpp
)
