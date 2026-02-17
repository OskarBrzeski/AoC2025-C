#include <stdbool.h>
#include <stdint.h>

#include "../utility.h"

typedef struct {
	i64 rows;
	i64 cols;
	char **floor;
} d4_floor;

typedef struct {
	i64 row;
	i64 col;
} d4_pos;

typedef struct {
	i64 length;
	d4_pos *positions;
} d4_removable;

i64 day4part1(char *filepath);
i64 day4part2(char *filepath);

d4_floor d4_new_floor(void);
void d4_parse_file(char *filepath, d4_floor *floor);

i64 d4_remove_all_rolls(d4_floor *floor, bool recursive);
void d4_get_removable_rolls(d4_floor *floor, d4_removable *removable);
i64 d4_surrounds(d4_floor *floor, i64 row, i64 col);
void d4_remove_rools(d4_floor *floor, d4_removable *removable);

