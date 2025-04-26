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

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_sub_string_empty_string);

    return UNITY_END();
}
