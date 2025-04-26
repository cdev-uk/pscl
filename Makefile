# Output directory for object files
BIN_DIR := bin

SRC := $(shell find src -name "*.c" 2>/dev/null) # find all .c files in src/
SRC_OBJ := $(SRC:.c=.o)

TESTS := $(shell find tests -name "*.c" 2>/dev/null) # find all .c files in tests/
TESTS_OBJ := $(TESTS:.c=.o)

# We only want to build binaries of tests - one binary per test file
BIN := $(shell echo $(TESTS) | sed 's/\.c//g' | sed 's#tests/#$(BIN_DIR)/#') # convert each tests/name_test.c -> bin/name_test

UNITY_SRC := Unity/src

CC = clang
CFLAGS = -Wall -Wextra -Werror -pedantic -I include -I src -I $(UNITY_SRC)

# default rule is to run all the tests
test: $(BIN)
	@for file in $(BIN_DIR)/*; do \
		if [ -x $$file ] && [ ! -d $$file ]; then \
			$$file; \
		fi; \
	done

# create the bin directory if it does not already exist
$(BIN_DIR):
	test -d $(BIN_DIR) || mkdir $(BIN_DIR)

# every binary depends on the bin directory and the source objects
$(BIN): $(BIN_DIR) $(SRC_OBJ)

# convert each test object into a binary
$(BIN): $(TESTS_OBJ)
	$(CC) $(CFLAGS) $< $(SRC_OBJ) $(UNITY_SRC)/unity.c -o $@

clean:
	rm -rf $(BIN_DIR)
	rm -f $(SRC_OBJ)
	rm -f $(TESTS_OBJ)

.PHONY: clean
