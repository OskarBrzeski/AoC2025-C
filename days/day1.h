#include <stdint.h>

typedef struct {
  int32_t capacity;
  int32_t length;
  int32_t *values;
} d1_rotations;

int32_t day1part1(char *filename);
int32_t day1part2(char *filename);

d1_rotations d1_new_rotations(void);
void d1_free_rotations(d1_rotations *rotations);

void d1_parse_file(char *filepath, d1_rotations *rotations);

int32_t d1_simulate_dial(d1_rotations *rotations);
int32_t d1_simulate_dial2(d1_rotations *rotations);
