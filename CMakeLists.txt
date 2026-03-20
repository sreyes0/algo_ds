cmake_minimum_required(VERSION 4.2)

project("Algorithms and Data Structures")

# Commands to add content at configure time
Include(FetchContent)
Include(CTest)

# Add Catch2 (unit testing)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git 
  GIT_TAG v3.13.0
)

FetchContent_MakeAvailable(Catch2)

# Gather algorithm soure files
file(GLOB ALGO_SOURCE CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/algorithms/sorting/*/src/*.cpp"
)

foreach(src ${ALGO_SOURCE})
    get_filename_component(name ${src} NAME_WE)

    # Algorithm files contain only implementation and lack main()
    # -> to be built as a library
    add_library(${name})

    # Associate properties with target
    # Note: paths are either absolute or relative to CMAKE_CURRENT_SOURCE_DIR
    target_sources(${name} PRIVATE ${src})
endforeach()

# Gather test source files
file(GLOB TEST_SOURCE CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/algorithms/sorting/*/test/test_*.cpp"
)

foreach(src ${TEST_SOURCE})
    get_filename_component(name ${src} NAME_WE)

    # Create target for corresponding test bench
    add_executable(${name})
    target_sources(${name} PRIVATE ${src})

    string(REPLACE "test_" "" executable ${name})

    # Link with Catch2
    target_link_libraries(${name}
      PRIVATE
        ${executable}
        Catch2::Catch2WithMain
    )

    # Register unit test executables
    add_test(NAME ${name} COMMAND ${name})
endforeach()

