# C++ Project Makefile
# Easy to extend by adding source files to SOURCES variable

# Compiler settings
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -g
LDFLAGS = 

# Directories
SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin

# Project name
TARGET = ccwc

# Source files (automatically find all .cpp files in src directory)
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# Include directories
INCLUDES = -I$(INCDIR)

# Default target
all: directories $(BINDIR)/$(TARGET)

# Create necessary directories
directories:
	@mkdir -p $(OBJDIR) $(BINDIR)

# Link the final executable
$(BINDIR)/$(TARGET): $(OBJECTS)
	@echo "Linking $@"
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

# Compile source files to object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@echo "Compiling $<"
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Clean build artifacts
clean:
	@echo "Cleaning build artifacts"
	rm -rf $(OBJDIR) $(BINDIR)

# Run the program
run: $(BINDIR)/$(TARGET)
	@echo "Running $(TARGET)"
	./$(BINDIR)/$(TARGET)

# Debug build
debug: CXXFLAGS += -DDEBUG -O0
debug: all

# Release build
release: CXXFLAGS += -O3 -DNDEBUG
release: all

# Install dependencies (placeholder - customize as needed)
install-deps:
	@echo "No dependencies to install currently"

# Show help
help:
	@echo "Available targets:"
	@echo "  all       - Build the project (default)"
	@echo "  clean     - Remove build artifacts"
	@echo "  run       - Build and run the program"
	@echo "  debug     - Build with debug flags"
	@echo "  release   - Build with optimization flags"
	@echo "  help      - Show this help message"

# Prevent make from trying to build these as files
.PHONY: all clean run debug release directories install-deps help

# Automatic dependency generation
-include $(OBJECTS:.o=.d)

$(OBJDIR)/%.d: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -MM -MT $(@:.d=.o) $< > $@ 