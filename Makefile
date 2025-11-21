# Compiler and flags
CC 				= gcc
CXX 			= g++
CFLAGS 			= -Wall -Wextra -Iinclude -fPIC -pedantic -O2 #-g
CXXFLAGS 		= -Wall -Wextra -Iinclude -fPIC -O2 #-g
CPPUTESTFLAGS 	= -lCppUTest -lCppUTestExt

# Directories
BIN_DIR 	= bin
SRC_DIR 	= src
TEST_DIR 	= test
OBJ_DIR 	= build
INCLUDE_DIR = include

# Find all source files
SRCS = $(shell find $(SRC_DIR) -name '*.c')
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/src/%.o, $(SRCS))

# Find all test files
TESTS 		= $(shell find $(TEST_DIR) -name '*.cpp')
TEST_OBJS 	= $(patsubst $(TEST_DIR)/%.cpp, $(OBJ_DIR)/test/%.o, $(TESTS))

# Targets
TARGET_STATIC = $(BIN_DIR)/libasterix.a
TARGET_SHARED = $(BIN_DIR)/libasterix.so
TARGET_TEST   = $(BIN_DIR)/libasterix_test

# ANSI escape codes
GREEN	= \033[0;32m
NC		= \033[0m

############################ Compilation procedures ############################

# Compile C sources for the library
$(OBJ_DIR)/src/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile C++ sources for tests
$(OBJ_DIR)/test/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET_STATIC): $(OBJS) | $(BIN_DIR)
	ar rcs $@ $^

$(TARGET_SHARED): $(OBJS) | $(BIN_DIR)
	$(CC) -shared -o $@ $^

$(TARGET_TEST): $(TEST_OBJS) $(OBJS) | $(BIN_DIR)
	$(CXX) -o $@ $^ $(CPPUTESTFLAGS)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

############################## Makefile commands ###############################

# Build all targets (shared and static libraries, and tests suite)
all: $(TARGET_SHARED) $(TARGET_STATIC) $(TARGET_TEST)

# Compile as shared library only
shared: $(TARGET_SHARED)

# Compile as static library only
static:  $(TARGET_STATIC)

# Compile and run tests
test: $(TARGET_TEST)
	@echo "\n${GREEN}Tests compiled!${NC}"
	@echo "\n${GREEN}Running tests...${NC}\n"
	./$(TARGET_TEST)
	@echo "${GREEN}Tests finished...${NC}\n"

# Clean up all compilation files
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all shared static test clean
