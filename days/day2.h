#include <stdint.h>

typedef struct {
  int64_t start;
  int64_t end;
} d2_range;

typedef struct {
  int64_t length;
  int64_t capacity;
  d2_range *ranges;
} d2_ranges;

int64_t day2part1(char *filepath);
int64_t day2part2(char *filepath);

d2_ranges d2_new_ranges(void);
void d2_free_ranges(d2_ranges ranges);

void d2_parse_file(char *filepath, d2_ranges *ranges);
d2_range d2_get_single_range(char *buffer);

int64_t d2_invalid_ids(d2_ranges ranges);
int64_t d2_invalid_ids2(d2_ranges ranges);

int64_t d2_10_exp(int64_t exp);
bool d2_contains(int64_t *array, int64_t length, int64_t num);
