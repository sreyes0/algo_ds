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

# Create a target
add_executable(insertion_sort)

# Associate properties with target
# Note: paths are either absolute or relative to CMAKE_CURRENT_SOURCE_DIR
target_sources(insertion_sort
  PRIVATE   # Scope (nothing depends on the source file -> PRIVATE)
    algorithms/sorting/insertion_sort/src/insertion_sort.cpp
)

# Link with Catch2
target_link_libraries(insertion_sort
  PRIVATE
    Catch2::Catch2WithMain
)
