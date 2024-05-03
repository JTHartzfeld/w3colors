# Makefile

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -std=c99

# Directories
SRC_DIR = src
BLD_DIR = bld
OBJ_DIR = obj
INST_ROOT = /usr

# Target library names
TARGET = w3colors
TARGET_STATIC = lib$(TARGET).a
TARGET_SHARED = lib$(TARGET).so
TARGET_DOC    = $(TARGET).3
TARGET_DOC_GZ = $(TARGET_DOC).gz
BLD_TARGETS = $(BLD_DIR)/$(TARGET_STATIC) $(BLD_DIR)/$(TARGET_SHARED) $(BLD_DIR)/$(TARGET_DOC_GZ)
README = README.md


# Find all the C files in the src/ directory
SOURCES = $(SRC_DIR)/$(TARGET).c

# Object files (one for each source file)
OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SOURCES))

# Default target
all: configure build

configure:
	@echo "Building source and files from templates..."
	@./mksrc
	@echo "Done.\n"

build: $(BLD_TARGETS)
	@rm -f $(OBJECTS)

# Rule to build documentation
$(BLD_DIR)/$(TARGET_DOC_GZ):
	@echo "Building manpages..."
	@pandoc -s -t man $(README) -o $(BLD_DIR)/$(TARGET_DOC)
	@gzip -f $(BLD_DIR)/$(TARGET_DOC)
	@echo "Done.\n"

# Rule to make the obj directory
$(OBJ_DIR):
	@mkdir $(OBJ_DIR)
	
$(BLD_DIR):
	@mkdir $(BLD_DIR)


# Rule to build the static library
$(BLD_DIR)/$(TARGET_STATIC): $(OBJECTS)
	@ar rcs $@ $^

# Rule to build the shared library
$(BLD_DIR)/$(TARGET_SHARED): $(OBJECTS)
	$(CC) -shared -o $@ $^

# Rule to compile source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR) $(BLD_DIR)
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

install: configure build
	@echo "Copying library files into $(INST_ROOT)/lib ..."
	@cp -p $(BLD_DIR)/$(TARGET_STATIC) $(INST_ROOT)/lib
	@cp -p $(BLD_DIR)/$(TARGET_SHARED) $(INST_ROOT)/lib
	@echo "Done.\n"
	@echo "Copying header into $(INST_ROOT)/include ..."
	@cp -p $(SRC_DIR)/$(TARGET).h $(INST_ROOT)/include
	@cp -p $(BLD_DIR)/$(TARGET).3.gz $(INST_ROOT)/share/man/man3
	@echo "Done.\n"
	
uninstall:
	@echo "Uninstalling from $(INST_ROOT) ...";
	
	@echo "Removing $(INST_ROOT)/lib/$(TARGET_SHARED) ..."
	@rm -f $(INST_ROOT)/lib/$(TARGET_SHARED)
	@echo "Done.\n"
	
	@echo "Removing $(INST_ROOT)/lib/$(TARGET_SHARED) ..."
	@rm -f $(INST_ROOT)/lib/$(TARGET_STATIC)
	@echo "Done.\n"
	
	@echo "Removing $(INST_ROOT)/lib/$(TARGET).h ..."
	@rm -f $(INST_ROOT)/include/$(TARGET).h
	@echo "Done.\n"
	
	@echo "Removing $(INST_ROOT)/share/man/man3/$(TARGET_DOC_GZ) ..."
	@rm -f $(INST_ROOT)/share/man/man3/$(TARGET_DOC_GZ)
	@echo "Done.\n"	
	
clean:
	@echo "Cleaning the workspace..."
	@rm -fr $(OBJ_DIR) $(BLD_DIR)
	@echo "Done.\n"
	
.PHONY: all auto configure build install syspkg localpkg clean

