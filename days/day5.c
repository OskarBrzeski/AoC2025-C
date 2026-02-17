#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../utility.h"
#include "day5.h"


i64 day5part1(char *filepath) {
	d5_ranges ranges = d5_new_ranges();
	d5_ids ids = d5_new_ids();

	d5_parse_file(filepath, &ranges, &ids);
	i64 answer = d5_count_fresh(&ranges, &ids);

	free(ids.ids);
	free(ranges.ranges);
	return answer;
}


i64 day5part2(char *filepath) {
	d5_ranges ranges = d5_new_ranges();
	d5_ids ids = d5_new_ids();

	d5_parse_file(filepath, &ranges, &ids);
	i64 answer = d5_count_all_fresh(&ranges);

	free(ids.ids);
	free(ranges.ranges);
	return answer;
}


d5_ranges d5_new_ranges(void) {
	d5_ranges ranges = {
		.length = 0,
		.ranges = calloc(200, sizeof(d5_range)),
	};

	return ranges;
}


d5_ids d5_new_ids(void) {
	d5_ids ids = {
		.length = 0,
		.ids = calloc(1100, sizeof(i64)),
	};

	return ids;
}


void d5_parse_file(char *filepath, d5_ranges *ranges, d5_ids *ids) {
	FILE *file = fopen(filepath, "r");
	
	const i64 BUFFER_SIZE = 200;
	char *buffer = calloc(BUFFER_SIZE, sizeof(char));
	
	while (fgets(buffer, BUFFER_SIZE, file)) {
		if (buffer[0] == '\n') break;

		u_strip_newline(buffer);
		ranges->ranges[ranges->length++] = d5_get_range(buffer);

		u_reset_buffer(buffer, BUFFER_SIZE);
	}

	while (fgets(buffer, BUFFER_SIZE, file)) {
		u_strip_newline(buffer);
		ids->ids[ids->length++] = atol(buffer);

		u_reset_buffer(buffer, BUFFER_SIZE);
	}

	free(buffer);
	fclose(file);
}


d5_range d5_get_range(char *buffer) {
	i64 i = 0;
	while (buffer[i] != '-') i++;
	buffer[i] = '\0';

	return (d5_range) {
		.start = atol(buffer),
		.end = atol(buffer + i + 1),
	};
}


i64 d5_count_fresh(d5_ranges *ranges, d5_ids *ids) {
	i64 total = 0;

	for (i64 i = 0; i < ids->length; i++) {
		if (d5_is_fresh(ranges, ids->ids[i])) total++;
	}

	return total;
}


bool d5_is_fresh(d5_ranges *ranges, i64 id) {
	for (i64 i = 0; i < ranges->length; i++) {
		d5_range range = ranges->ranges[i];

		if (id >= range.start && id <= range.end) return true;
	}
	return false;
}


i64 d5_count_all_fresh(d5_ranges *ranges) {
	d5_ranges merged = d5_new_ranges();

	for (i64 i = 0; i < ranges->length; i++) {
		d5_range current = ranges->ranges[i];
		d5_merge_range(&merged, current);
	}

	i64 total = 0;
	for (i64 i = 0; i < merged.length; i++) {
		d5_range current = merged.ranges[i];
		total += current.end - current.start + 1;
	}

	return total;
}


void d5_merge_range(d5_ranges *merged, d5_range range) {
	for (i64 i = 0; i < merged->length; i++) {
		d5_range current = merged->ranges[i];

		if (range.end + 1 < current.start) continue;
		if (range.start - 1 > current.end) continue;

		if (range.start >= current.start && range.end <= current.end) {
			return;
		}
		if (range.start <= current.start && range.end >= current.end) {
			d5_remove_current_range(merged, i--);
			continue;
		}

		if (range.end + 1 >= current.start) {
			range.start = u_min(range.start, current.start);
			range.end = u_max(range.end, current.end);
			d5_remove_current_range(merged, i--);
		}
		else if (range.start - 1 <= current.end) {
			range.start = u_min(range.start, current.start);
			range.end = u_max(range.end, current.end);
			d5_remove_current_range(merged, i--);
		}
	}

	merged->ranges[merged->length++] = range;
}


void d5_remove_current_range(d5_ranges *merged, int64_t index) {
	while (index < merged->length - 1) {
		merged->ranges[index] = merged->ranges[index + 1];
		index++;
	}

	merged->length--;
}

