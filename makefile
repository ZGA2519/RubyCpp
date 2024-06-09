# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++20 -Wall -I./include

# Linker flags
LDFLAGS = 

# Executable name
TARGET = main

# Source files
SRCS = main.cpp \
       include/IntegerWrapper.cpp \
       include/StringWrapper.cpp \
	   include/ListWrapper.cpp \

# Object files
OBJS = $(SRCS:.cpp=.o)

# Include dependencies
DEPS = $(SRCS:.cpp=.d)

# Default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

# Compile source files into object files and generate dependencies
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

# Include dependency files
-include $(DEPS)

# Clean target to remove generated files
clean:
	rm -f $(OBJS) $(DEPS) $(TARGET)

# Phony targets
.PHONY: all clean
