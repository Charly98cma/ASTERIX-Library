# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -fPIC
LDFLAGS = 

# Directories
SRC_DIR = src
OBJ_DIR = build
INCLUDE_DIR = include

# Find all source files
SRCS = $(shell find $(SRC_DIR) -name '*.c')
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Target
TARGET_STATIC = libasterix.a
TARGET_SHARED = libasterix.so

# Default build: shared library
all: $(TARGET_SHARED)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET_STATIC): $(OBJS)
	ar rcs $@ $^

$(TARGET_SHARED): $(OBJS)
	$(CC) -shared -o $@ $^

clean:
	rm -rf $(OBJ_DIR) $(TARGET_STATIC) $(TARGET_SHARED)

.PHONY: all clean
