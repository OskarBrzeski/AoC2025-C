#include <stdint.h>
#include <stdbool.h>

#include "../utility.h"

typedef struct {
	i64 start;
	i64 end;
} d2_range;

typedef struct {
	i64 length;
	d2_range *ranges;
} d2_ranges;

i64 day2part1(char *filepath);
i64 day2part2(char *filepath);

d2_ranges d2_new_ranges(void);
void d2_parse_file(char *filepath, d2_ranges *ranges);
d2_range d2_get_single_range(char *buffer);
i64 d2_get_number(char **buffer);

i64 d2_invalid_ids(d2_ranges ranges);
i64 d2_invalid_ids2(d2_ranges ranges);

i64 d2_10_exp(i64 exp);
bool d2_contains(i64 *array, i64 length, i64 num);

