#include <stdbool.h>
#include <stdint.h>

#include "../utility.h"

typedef struct {
	i64 start;
	i64 end;
} d5_range;

typedef struct {
	i64 length;
	d5_range *ranges;
} d5_ranges;

typedef struct {
	i64 length;
	i64 *ids;
} d5_ids;

i64 day5part1(char *filepath);
i64 day5part2(char *filepath);

d5_ranges d5_new_ranges(void);
d5_ids d5_new_ids(void);
void d5_parse_file(char *filepath, d5_ranges *ranges, d5_ids *ids);
d5_range d5_get_range(char *buffer);

i64 d5_count_fresh(d5_ranges *ranges, d5_ids *ids);
bool d5_is_fresh(d5_ranges *ranges, i64 id);
i64 d5_count_all_fresh(d5_ranges *ranges);
void d5_merge_range(d5_ranges *merged, d5_range range);
void d5_remove_current_range(d5_ranges *merged, i64 index);

