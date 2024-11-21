# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra -I./include

# Target executable
TARGET = raytracer

# Source files
SRCS = raytracer.cpp cylinder.cpp sphere.cpp triangle.cpp ray.cpp traceRay.cpp 

# Header files
HDRS = raytracer.h cylinder.h sphere.h triangle.h ray.h traceRay.h ppmWriter.h vecGeometry.h

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files into object files
%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean