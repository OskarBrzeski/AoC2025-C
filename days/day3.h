#include <stdint.h>

#include "../utility.h"

typedef struct {
	i64 length;
	char **banks;
} d3_banks;

i64 day3part1(char *filepath);
i64 day3part2(char *filepath);

d3_banks d3_new_banks(void);
void d3_parse_file(char *filepath, d3_banks *banks);

i64 d3_joltage_total(d3_banks *banks, i64 amount);
i64 d3_bank_joltage(char *bank, i64 amount);

