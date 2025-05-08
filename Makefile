# Output directory for object files
BIN_DIR := bin
UNITY_INCLUDE := Unity/src
UNITY_HEADER := Unity/src/unity.h
UNITY_SRC := Unity/src/unity.c

CC := clang
CFLAGS := -Wall -Wextra -Werror --std=c89 -pedantic -I include -I src -I $(UNITY_INCLUDE)

TEST_BINARIES = $(BIN_DIR)/strings_test
TEST_BINARIES += $(BIN_DIR)/math_test

# default rule is to run all the tests
test: $(TEST_BINARIES)
	@for file in $(BIN_DIR)/*; do \
		if [ -x $$file ] && [ ! -d $$file ]; then \
			$$file; \
		fi; \
	done

# create the bin directory if it does not already exist
$(BIN_DIR):
	test -d $(BIN_DIR) || mkdir $(BIN_DIR)

$(BIN_DIR)/math_test: $(BIN_DIR) tests/math_test.c src/math.c include/math.h $(UNITY_SRC) $(UNITY_HEADER)
	$(CC) $(CFLAGS) tests/math_test.c src/math.c $(UNITY_SRC) -o $@

$(BIN_DIR)/strings_test: $(BIN_DIR) tests/strings_test.c src/strings.c include/strings.h $(UNITY_SRC) $(UNITY_HEADER)
	$(CC) $(CFLAGS) tests/strings_test.c src/strings.c $(UNITY_SRC) -o $@

clean:
	rm -rf $(BIN_DIR)

.PHONY: clean
.PHONY: test
