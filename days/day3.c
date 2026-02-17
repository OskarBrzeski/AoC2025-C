#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utility.h"
#include "day3.h"


i64 day3part1(char *filepath) {
	d3_banks banks = d3_new_banks();

	d3_parse_file(filepath, &banks);
	i64 total = d3_joltage_total(&banks, 2);

	free(banks.banks);
	return total;
}


i64 day3part2(char *filepath) {
	d3_banks banks = d3_new_banks();

	d3_parse_file(filepath, &banks);
	i64 total = d3_joltage_total(&banks, 12);

	free(banks.banks);
	return total;
}


d3_banks d3_new_banks(void) {
	d3_banks banks = {
		.length = 0,
		.banks = calloc(200, sizeof(char *)),
	};

	return banks;
}


void d3_parse_file(char *filepath, d3_banks *banks) {
	FILE *file = fopen(filepath, "r");

	const i64 BUFFER_SIZE = 10000;
	char *buffer = calloc(BUFFER_SIZE, sizeof(char));

	while (fgets(buffer, BUFFER_SIZE, file)) {
		buffer[strlen(buffer) - 1] = '\0';
		banks->banks[banks->length++] = buffer;

		buffer = calloc(BUFFER_SIZE, sizeof(char));
	}

	free(buffer);
	fclose(file);
}


i64 d3_joltage_total(d3_banks *banks, i64 amount) {
	i64 total = 0;

	for (int i = 0; i < banks->length; i++) {
		total += d3_bank_joltage(banks->banks[i], amount);
	}

	return total;
}


i64 d3_bank_joltage(char *bank, i64 amount) {
	i64 bank_len = strlen(bank);

	i64 total = 0;
	i64 curr = 0;
	i64 index = 0;
	for (int j = 1; j <= amount; j++) {
		for (int i = index; i < bank_len - amount + j; i++) {
			i64 digit = bank[i] - 48;
			if (digit > curr) {
				curr = digit;
				index = i;
			}
		}

		total = total * 10 + curr;
		curr = 0;
		index++;
	}

	return total;
}

