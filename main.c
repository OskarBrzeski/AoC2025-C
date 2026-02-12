#include <stdio.h>

#include "days/day1.h"
#include "days/day2.h"

int main() {
    printf("==========================================================\n");
    printf("=           Advent of Code 2025 - Written in C           =\n");
    printf("==========================================================\n");
    printf("Day 1:\n");
    printf("    Test: Part 1: %d | Part 2: %d\n", day1part1("data/day1test.txt"), day1part2("data/day1test.txt"));
    printf("    Real: Part 1: %d | Part 2: %d\n", day1part1("data/day1.txt"), day1part2("data/day1.txt"));
    printf("Day 2:\n");
    printf("    Test: Part 1: %ld | Part 2: %ld\n", day2part1("data/day2test.txt"), day2part2("data/day2test.txt"));
    printf("    Real: Part 1: %ld | Part 2: %ld\n", day2part1("data/day2.txt"), day2part2("data/day2.txt"));
    printf("==========================================================\n");

    return 0;
}
