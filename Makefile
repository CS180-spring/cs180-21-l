# The C++ compiler to use
CXX = g++

# Flags to pass to the C++ compiler
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic

# The name of the output executable
TARGET = program

# Source files for the program
SRCS = main.cpp

# Object files generated during compilation
OBJS = $(SRCS:.cpp=.o)

# Default rule to build the program
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile the source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Rule to clean up object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)