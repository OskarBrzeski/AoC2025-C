#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "day2.h"


int64_t
day2part1(char *filepath) {
    d2_ranges ranges = d2_new_ranges();

    d2_parse_file(filepath, &ranges);

    int64_t result = d2_invalid_ids(ranges);

    return result;
}


int64_t
day2part2(char *filepath) {
    d2_ranges ranges = d2_new_ranges();

    d2_parse_file(filepath, &ranges);

    int64_t result = d2_invalid_ids2(ranges);

    return result;
}


d2_ranges d2_new_ranges(void) {
    const int32_t RANGE_CAPACITY = 1000;

    d2_ranges ranges = {
        .length = 0,
        .capacity = RANGE_CAPACITY,
        .ranges = calloc(RANGE_CAPACITY, sizeof(d2_range)),
    };

    return ranges;
}


void d2_free_ranges(d2_ranges ranges) {
    free(ranges.ranges);
}


void
d2_parse_file(char *filepath, d2_ranges *ranges) {
    FILE *file = fopen(filepath, "r");

    const int32_t BUFFER_SIZE = 65536;
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
}

d2_range
d2_get_single_range(char *buffer) {
    int64_t start, end;

    int i = 0;
    while (buffer[i] != '-') {
        i++;
    }
    char *start_str = calloc(100, sizeof(char));
    strncpy(start_str, buffer, i);
    start = atol(start_str);

    buffer += i+1;
    i = 0;
    while (buffer[i] != ',' && buffer[i] != '\0') {
        i++;
    }
    char *end_str = calloc(100, sizeof(char));
    strncpy(end_str, buffer, i);
    end = atol(end_str);

    return (d2_range){.start = start, .end = end};
}


int64_t
d2_invalid_ids(d2_ranges ranges) {
    int64_t total = 0;
    int64_t base = 1;
    int64_t power = 1;

    for (int i = 0; i < ranges.length; i++) {
        d2_range range = ranges.ranges[i];

        int64_t current;
        do {
            current = base * d2_10_exp(power) + base;
            if (current >= range.start && current <= range.end) {
                total += current;
            }
            base++;
            if (base % d2_10_exp(power) == 0) {
                power++;
            }
        } while (current <= range.end);

        base = 1;
        power = 1;
    }

    return total;
}


int64_t
d2_invalid_ids2(d2_ranges ranges) {
    int64_t total = 0;
    int64_t base = 1;
    int64_t power = 1;

    for (int i = 0; i < ranges.length; i++) {
        d2_range range = ranges.ranges[i];

        int64_t current;
        int64_t *found = calloc(10000, sizeof(int64_t));
        int64_t found_len = 0;
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
            if (base % d2_10_exp(power) == 0) {
                power++;
            }
        } while (base * d2_10_exp(power) + base <= range.end);

        base = 1;
        power = 1;

        free(found);
        found = calloc(10000, sizeof(int64_t));
    }

    return total;
}


int64_t
d2_10_exp(int64_t exp) {
    int64_t result = 1;
    for (int i = 0; i < exp; i++) {
        result *= 10;
    }
    return result;
}


bool
d2_contains(int64_t *array, int64_t length, int64_t num) {
    for (int i = 0; i < length; i++) {
        if (array[i] == num) {
            return true;
        }
    }

    return false;
}
