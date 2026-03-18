# algo_ds
Implementations of algorithms and data structures

## git 

### commit conventions
* fix(<feature>)
* refactor(<feature>)
    * refactoring or maintenance work
* doc(<feature>)
    * Documentation purposes (readme, comments, etc)
* test(<feature>)
    * Unit tests or testing infrastructure
* feat(<feature>)
    * Implementation of e.g. an algorithm or a data structure
* build(<feature>)
    * Changes to CI/CD
* misc(<feature>)
    * Anything that does not fall in any other category

## CMake

### Use
`cmake -B build`
`cmake --build build`

### Notes 
Commands to describe output artifacts
* add_executable()
* add_library()

Associate input files with respective output artifact
* target_sources()

Associate output artifacts with one another
* target_link_libraries()

Target:
  - artifacts (executable, library, header collection, etc
  - source files
  - include directories
  - dependencies
  - compiler and linker flags
  - etc

## ToDo
* Use Catch2 framework for unit testing
* Migrate to CMake at some point
