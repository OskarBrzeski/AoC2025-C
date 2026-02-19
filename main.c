#include <stdio.h>

#include "days/day1.h"
#include "days/day2.h"
#include "days/day3.h"
#include "days/day4.h"
#include "days/day5.h"
#include "days/day6.h"

int main() {
	printf("==========================================================\n");
	printf("===         Advent of Code 2025 - Written in C         ===\n");
	printf("==========================================================\n");
	printf("Day 1:\n");
	printf("    Test: Part 1: %ld | Part 2: %ld\n", day1part1("data/day1test.txt"), day1part2("data/day1test.txt"));
	printf("    Real: Part 1: %ld | Part 2: %ld\n", day1part1("data/day1.txt"), day1part2("data/day1.txt"));
	printf("Day 2:\n");
	printf("    Test: Part 1: %ld | Part 2: %ld\n", day2part1("data/day2test.txt"), day2part2("data/day2test.txt"));
	printf("    Real: Part 1: %ld | Part 2: %ld\n", day2part1("data/day2.txt"), day2part2("data/day2.txt"));
	printf("Day 3:\n");
	printf("    Test: Part 1: %ld | Part 2: %ld\n", day3part1("data/day3test.txt"), day3part2("data/day3test.txt"));
	printf("    Real: Part 1: %ld | Part 2: %ld\n", day3part1("data/day3.txt"), day3part2("data/day3.txt"));
	printf("Day 4:\n");
	printf("    Test: Part 1: %ld | Part 2: %ld\n", day4part1("data/day4test.txt"), day4part2("data/day4test.txt"));
	printf("    Real: Part 1: %ld | Part 2: %ld\n", day4part1("data/day4.txt"), day4part2("data/day4.txt"));
	printf("Day 5:\n");
	printf("    Test: Part 1: %ld | Part 2: %ld\n", day5part1("data/day5test.txt"), day5part2("data/day5test.txt"));
	printf("    Real: Part 1: %ld | Part 2: %ld\n", day5part1("data/day5.txt"), day5part2("data/day5.txt"));
	printf("Day 6:\n");
	printf("    Test: Part 1: %ld | Part 2: %ld\n", day6part1("data/day6test.txt"), day6part2("data/day6test.txt"));
	printf("    Real: Part 1: %ld | Part 2: %ld\n", day6part1("data/day6.txt"), day6part2("data/day6.txt"));
	printf("==========================================================\n");

	return 0;
}

