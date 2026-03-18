cmake_minimum_required(VERSION 4.2)

project("Algorithms and Data Structures")

# Commands to add content at configure time
Include(FetchContent)

# Add Catch2 (unit testing)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git 
  GIT_TAG v3.13.0
)

FetchContent_MakeAvailable(Catch2)

# Since insertion_sort only contains an algorithm and lacks main()
# it has to be built as a library
add_library(insertion_sort)

# Associate properties with target
# Note: paths are either absolute or relative to CMAKE_CURRENT_SOURCE_DIR
target_sources(insertion_sort
  PRIVATE   # Scope (nothing depends on the source file -> PRIVATE)
    algorithms/sorting/insertion_sort/src/insertion_sort.cpp
)

# Create target for corresponding test bench
add_executable(test_insertion_sort)
target_sources(test_insertion_sort
  PRIVATE
    algorithms/sorting/insertion_sort/test/test_insertion_sort.cpp
)

# Link with Catch2
target_link_libraries(test_insertion_sort
  PRIVATE
    insertion_sort
    Catch2::Catch2WithMain
)
