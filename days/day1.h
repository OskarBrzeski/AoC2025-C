#include <stdint.h>

#include "../utility.h"

typedef struct {
	i64 length;
	i64 *values;
} d1_rotations;

i64 day1part1(char *filename);
i64 day1part2(char *filename);

d1_rotations d1_new_rotations(void);
void d1_parse_file(char *filepath, d1_rotations *rotations);

i64 d1_simulate_dial(d1_rotations *rotations);
i64 d1_simulate_dial2(d1_rotations *rotations);

