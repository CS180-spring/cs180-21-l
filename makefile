CXX = g++
CXXFLAGS = -std=c++17 -Wall

# List of source files
SRCS = main.cpp Database.cpp Movie.cpp File.cpp Person.cpp

# Generate the object file names based on source file names
OBJS = main.o Database.o File.o Movie.o Person.o

# Output executable name
EXECUTABLE = movie_database

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXECUTABLE)