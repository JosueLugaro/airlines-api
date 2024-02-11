# Compiler
CXX = g++

# preprocesser flags
CPPFLAGS = -iquote src -MMD -MP

# Compiler flags (-l is a linker flag but I've left it here for ease)
CXXFLAGS = -std=c++23 -l httpserver -l pqxx -l pq

# Directories
BUILD_DIR = build
SRC_DIR = src

# Source, Object, and Dependency files
SRCS := $(wildcard $(SRC_DIR)/*/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))
DEPENDS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.d, $(SRCS))

# Include dependency files to support
# header file changes triggering recompilation
-include $(DEPENDS)

# Link executable from object files
build/main: $(OBJS)
	@echo Linking object files...
	@$(CXX) $^ $(CPPFLAGS) $(CXXFLAGS) -o $@

# Build object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp Makefile
	@echo Compiling $< to object file $@
	@mkdir -p $(dir $@)
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: run dirs clean blah

run:
	@echo Running executable...
	@build/main

clean:
	@echo Cleaning up build directory...
	@rm -rf build
