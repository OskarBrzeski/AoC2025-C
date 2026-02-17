#include <string.h>

#include "utility.h"


void u_strip_newline(char* buffer) {
	buffer[strlen(buffer) - 1] = '\0';
}


void u_reset_buffer(char *buffer, i64 buffer_size) {
	for (int i = 0; i < buffer_size; i++) {
		buffer[i] = 0;
	}
}


i64 u_min(i64 a, i64 b) {
	if (a < b) return a;
	return b;
}


i64 u_max(i64 a, i64 b) {
	if (a > b) return a;
	return b;
}
