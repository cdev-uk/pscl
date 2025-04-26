#include <string.h>

#include "strings.h"
#include "unity.h"

void setUp(void) {
    // Set up
}

void tearDown(void) {
    // Tear down
}

void test_sub_string_empty_string(void) {
    size_t output_length = 5;
    const char *input = "";
    char output[output_length];
    size_t sub_string_length = sub_string(input, 0, 0, output, output_length);

    TEST_ASSERT_EQUAL_size_t(0, sub_string_length);
    TEST_ASSERT_EQUAL_STRING("", output);
}

void test_sub_string_start_end_equal(void) {
    const char *input = "abcde";
    size_t output_length = strlen(input);
    char output[output_length];
    size_t sub_string_length = sub_string(input, 2, 2, output, output_length);

    TEST_ASSERT_EQUAL_size_t(0, sub_string_length);
    TEST_ASSERT_EQUAL_STRING("", output);
}

void test_sub_string_first_character(void) {
    const char *input = "abcde";
    size_t output_length = strlen(input);
    char output[output_length];
    size_t sub_string_length = sub_string(input, 0, 1, output, output_length);

    TEST_ASSERT_EQUAL_size_t(1, sub_string_length);
    TEST_ASSERT_EQUAL_STRING("a", output);
}

void test_sub_string_last_character(void) {
    const char *input = "abcde";
    size_t output_length = strlen(input);
    char output[output_length];
    size_t sub_string_length = sub_string(input, 4, 5, output, output_length);

    TEST_ASSERT_EQUAL_size_t(1, sub_string_length);
    TEST_ASSERT_EQUAL_STRING("e", output);
}

void test_char_count(void) {
    TEST_ASSERT_EQUAL_size_t(0, char_count("abcde", 'f'));
    TEST_ASSERT_EQUAL_size_t(1, char_count("abcde", 'a'));
    TEST_ASSERT_EQUAL_size_t(1, char_count("abcde", 'c'));
    TEST_ASSERT_EQUAL_size_t(1, char_count("abcde", 'e'));
    TEST_ASSERT_EQUAL_size_t(5, char_count("xxxxx", 'x'));
    TEST_ASSERT_EQUAL_size_t(3, char_count("axxxa", 'x'));
    TEST_ASSERT_EQUAL_size_t(3, char_count("xaxax", 'x'));
    TEST_ASSERT_EQUAL_size_t(2, char_count("axaxa", 'x'));
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_sub_string_empty_string);
    RUN_TEST(test_sub_string_start_end_equal);
    RUN_TEST(test_sub_string_first_character);
    RUN_TEST(test_sub_string_last_character);

    RUN_TEST(test_char_count);

    return UNITY_END();
}
