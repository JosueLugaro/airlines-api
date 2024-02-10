# Compiler
CXX = g++

# preprocesser flags
CPPFLAGS = -iquote src

# Compiler flags (-l is a linker flag but I've left it here for ease)
CXXFLAGS = -std=c++23 -l httpserver -l pqxx -l pq

# Directories
BUILD_DIR = build
SRC_DIR = src

# Object files
SRCS := $(wildcard $(SRC_DIR)/*/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))
# OBJECTS = main.o hello_world.o

# build_dir/target: src_dir/*/*.cpp src_dir/*/*.hpp
# compiler -o $@ flags -c $<

build/main: $(OBJS)
# $(CXX) $^ $(CPPFLAGS) $(CXXFLAGS) -o $@
	@echo "build main"

$(BUILD_DIR)/*/%.o: $(SRC_DIR)/*/%.cpp
#$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@
	@echo $@ "target"
	@echo $< "prereq"

# build/main.o: $(SRC)/entrypoint/main.cpp
# 	$(CXX) -o $@ $(CPPFLAGS) $(CXXFLAGS) -c $(SRC)/entrypoint/main.cpp

# build/hello_world.o: $(SRC)/hello_world/hello_world.cpp $(SRC)/hello_world/hello_world.hpp
# 	$(CXX) -o $@ $(CPPFLAGS) $(CXXFLAGS) -c $(SRC)/hello_world/hello_world.cpp

.PHONY: run dirs clean blah

blah:
	echo $(OBJS)

run:
	build/main

dirs:
	mkdir build

clean:
	rm -rf build
