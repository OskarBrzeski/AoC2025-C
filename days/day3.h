#include <stdint.h>

typedef struct {
  int64_t length;
  int64_t capacity;
  char **banks;
} d3_banks;

int64_t day3part1(char *filepath);
int64_t day3part2(char *filepath);

d3_banks d3_new_banks(void);
void d3_parse_file(char *filepath, d3_banks *banks);

int64_t d3_joltage_total(d3_banks *banks, int64_t amount);
int64_t d3_bank_joltage(char *bank, int64_t amount);
