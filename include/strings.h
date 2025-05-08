#ifndef PSCL_STRINGS_H
#define PSCL_STRINGS_H

#include <stddef.h>

size_t pscl_sub_string(
    const char *input,
    size_t start,
    size_t end,
    char *output,
    size_t output_lenght
);

size_t pscl_char_count(
    const char *input,
    const char search
);

#endif /* PSCL_STRINGS_H */
