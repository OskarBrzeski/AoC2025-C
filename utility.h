#pragma once

#include <stdint.h>

#define i64 int64_t

void u_strip_newline(char *buffer);
void u_reset_buffer(char *buffer, i64 buffer_size);
i64 u_min(i64 a, i64 b);
i64 u_max(i64 a, i64 b);
