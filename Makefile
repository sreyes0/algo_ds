# vim changes tabs for spaces automatically
.RECIPEPREFIX = |

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -pedantic-errors

ALGO_DIR := ./algorithms

# Find .cpp files to compile
SOURCES := $(shell find $(ALGO_DIR) -name *.cpp)
# Convert ./path/to/source.cpp to ./path/to/source 
TARGETS := $(SOURCES:.cpp=.out)

all: $(TARGETS)

# Generic rule with wildcard
%.out: %.cpp
| echo "Compiling '$@'..."
| $(CXX) $(CXXFLAGS) $< -o $@

# Clean workspaces
clean:
| echo "Cleaning workspaces..."
| find $(ALGO_DIR) -type f -executable -delete

# Execute all compiled programs
run: all
| echo "Running"
| echo "-------"
| @for exe in $(TARGETS); do \
|   echo "Execute $$exe"; \
|   $$exe; \
|   echo; \
| done
