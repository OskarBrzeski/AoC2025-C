#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "day3.h"


int64_t day3part1(char *filepath) {
    d3_banks banks = d3_new_banks();

    d3_parse_file(filepath, &banks);

    int64_t total = d3_joltage_total(&banks, 2);

    free(banks.banks);

    return total;
}


int64_t day3part2(char *filepath) {
    d3_banks banks = d3_new_banks();

    d3_parse_file(filepath, &banks);

    int64_t total = d3_joltage_total(&banks, 12);

    free(banks.banks);

    return total;
}


d3_banks d3_new_banks(void) {
    d3_banks banks = {
        .length = 0,
        .capacity = 200,
        .banks = calloc(200, sizeof(char *)),
    };

    return banks;
}


void d3_parse_file(char *filepath, d3_banks *banks) {
    FILE *file = fopen(filepath, "r");

    const int64_t BUFFER_SIZE = 10000;
    char *buffer = calloc(BUFFER_SIZE, sizeof(char));

    while (fgets(buffer, BUFFER_SIZE, file)) {
        buffer[strlen(buffer) - 1] = '\0';
        banks->banks[banks->length++] = buffer;

        buffer = calloc(BUFFER_SIZE, sizeof(char));
    }

    free(buffer);
}


int64_t d3_joltage_total(d3_banks *banks, int64_t amount) {
    int64_t total = 0;

    for (int i = 0; i < banks->length; i++) {
        total += d3_bank_joltage(banks->banks[i], amount);
    }

    return total;
}


int64_t d3_bank_joltage(char *bank, int64_t amount) {
    int64_t bank_len = strlen(bank);

    int64_t total = 0;
    int64_t curr = 0;
    size_t index = 0;
    for (int j = 1; j <= amount; j++) {
        for (int i = index; i < bank_len - amount + j; i++) {
            int64_t digit = bank[i] - 48;
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

