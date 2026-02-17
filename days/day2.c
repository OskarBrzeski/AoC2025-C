#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../utility.h"
#include "day2.h"


i64
day2part1(char *filepath) {
	d2_ranges ranges = d2_new_ranges();

	d2_parse_file(filepath, &ranges);
	i64 result = d2_invalid_ids(ranges);

	free(ranges.ranges);
	return result;
}


i64
day2part2(char *filepath) {
	d2_ranges ranges = d2_new_ranges();

	d2_parse_file(filepath, &ranges);
	i64 result = d2_invalid_ids2(ranges);

	free(ranges.ranges);
	return result;
}


d2_ranges d2_new_ranges(void) {
	const i64 RANGE_CAPACITY = 1000;

	d2_ranges ranges = {
		.length = 0,
		.ranges = calloc(RANGE_CAPACITY, sizeof(d2_range)),
	};

	return ranges;
}


void
d2_parse_file(char *filepath, d2_ranges *ranges) {
	FILE *file = fopen(filepath, "r");

	const i64 BUFFER_SIZE = 65536;
	char *buffer = calloc(BUFFER_SIZE, sizeof(char));
	fgets(buffer, BUFFER_SIZE, file);

	ranges->ranges[ranges->length++] = d2_get_single_range(buffer);

	int i = 0;
	do {
		if (buffer[i] == ',') {
			i++;
			ranges->ranges[ranges->length++] = d2_get_single_range(buffer + i);
		}
		i++;
	} while (buffer[i] != '\0');

	free(buffer);
	fclose(file);
}

d2_range
d2_get_single_range(char *buffer) {
	i64 start, end;

	start = d2_get_number(&buffer);
	end = d2_get_number(&buffer);

	return (d2_range){.start = start, .end = end};
}


i64 d2_get_number(char **buffer_ptr) {
	char *buffer = *buffer_ptr;

	int i = 0;
	while (buffer[i] != '-' && (buffer[i] != ',' && buffer[i] != '\0')) {i++;}

	char *new_str = calloc(100, sizeof(char));
	strncpy(new_str, buffer, i);
	i64 result = atol(new_str);

	free(new_str);
	*buffer_ptr += i+1;
	return result;
}


i64
d2_invalid_ids(d2_ranges ranges) {
	i64 total = 0;
	i64 base = 1;
	i64 power = 1;

	for (int i = 0; i < ranges.length; i++) {
		d2_range range = ranges.ranges[i];

		i64 current;
		do {
			current = base * d2_10_exp(power) + base;
			if (current >= range.start && current <= range.end) total += current;
			base++;
			if (base % d2_10_exp(power) == 0) power++;
		} while (current <= range.end);

		base = 1;
		power = 1;
	}

	return total;
}


i64
d2_invalid_ids2(d2_ranges ranges) {
	i64 total = 0;
	i64 base = 1;
	i64 power = 1;

	for (int i = 0; i < ranges.length; i++) {
		d2_range range = ranges.ranges[i];

		const i64 IDS_MAX_LENGTH = 10000;
		i64 *found = calloc(IDS_MAX_LENGTH, sizeof(i64));
		i64 found_len = 0;
		i64 current;
		do {
			current = base;
			do {
				current = current * d2_10_exp(power) + base;
				if (current >= range.start && current <= range.end) {
					if (d2_contains(found, found_len, current)) {
						continue;
					}
					total += current;
					found[found_len++] = current;
				}
			} while (current <= range.end);

			base++;
			if (base % d2_10_exp(power) == 0) power++;
		} while (base * d2_10_exp(power) + base <= range.end);

		base = 1;
		power = 1;

		free(found);
		found = calloc(IDS_MAX_LENGTH, sizeof(i64));
	}

	return total;
}


i64
d2_10_exp(i64 exp) {
	i64 result = 1;
	for (int i = 0; i < exp; i++) {
		result *= 10;
	}
	return result;
}


bool
d2_contains(i64 *array, i64 length, i64 num) {
	for (int i = 0; i < length; i++) {
		if (array[i] == num) return true;
	}

	return false;
}
