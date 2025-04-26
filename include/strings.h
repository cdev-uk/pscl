#ifndef PSCL_STRINGS_H
#define PSCL_STRINGS_H

#include <stddef.h>

size_t sub_string(
    const char *input,
    size_t start,
    size_t end,
    char *output,
    size_t output_lenght
);

#endif /* PSCL_STRINGS_H */
