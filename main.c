#include <stdio.h>

#include "days/day1.h"

int main() {
    printf("Advent of Code 2025 - Written in C\n");
    printf("Day 1:\n");
    printf("    Test: Part 1: %d | Part 2: %d\n", day1part1("data/day1test.txt"), day1part2("data/day1test.txt"));
    printf("    Real: Part 1: %d | Part 2: %d\n", day1part1("data/day1.txt"), day1part2("data/day1.txt"));

    return 0;
}
