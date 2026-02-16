#include <stdbool.h>
#include <stdint.h>

typedef struct {
	int64_t rows;
	int64_t cols;
	char **floor;
} d4_floor;

typedef struct {
	int64_t row;
	int64_t col;
} d4_pos;

typedef struct {
	int64_t length;
	d4_pos *positions;
} d4_removable;

int64_t day4part1(char *filepath);
int64_t day4part2(char *filepath);

d4_floor d4_new_floor(void);
void d4_parse_file(char *filepath, d4_floor *floor);

int64_t d4_remove_all_rolls(d4_floor *floor, bool recursive);
void d4_get_removable_rolls(d4_floor *floor, d4_removable *removable);
int64_t d4_surrounds(d4_floor *floor, int64_t row, int64_t col);
void d4_remove_rools(d4_floor *floor, d4_removable *removable);

