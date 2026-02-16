#include <stdio.h>

#include "days/day1.h"
#include "days/day2.h"
#include "days/day3.h"
#include "days/day4.h"

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
    printf("Day 3:\n");
    printf("    Test: Part 1: %ld | Part 2: %ld\n", day3part1("data/day3test.txt"), day3part2("data/day3test.txt"));
    printf("    Real: Part 1: %ld | Part 2: %ld\n", day3part1("data/day3.txt"), day3part2("data/day3.txt"));
    printf("Day 4:\n");
    printf("    Test: Part 1: %ld | Part 2: %ld\n", day4part1("data/day4test.txt"), day4part2("data/day4test.txt"));
    printf("    Real: Part 1: %ld | Part 2: %ld\n", day4part1("data/day4.txt"), day4part2("data/day4.txt"));
    printf("==========================================================\n");

    return 0;
}
