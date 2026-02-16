#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "day4.h"


const int64_t d4_MAX_FLOOR_SIZE = 140 * 140;


int64_t day4part1(char *filepath) {
	d4_floor floor = d4_new_floor();

	d4_parse_file(filepath, &floor);

	int64_t rolls = d4_remove_all_rolls(&floor, false);

	free(floor.floor);

	return rolls;
}


int64_t day4part2(char *filepath) {
	d4_floor floor = d4_new_floor();

	d4_parse_file(filepath, &floor);

	int64_t rolls = d4_remove_all_rolls(&floor, true);

	free(floor.floor);

	return rolls;
}


d4_floor d4_new_floor(void) {
	d4_floor floor = {
		.rows = 0,
		.cols = 0,
		.floor = calloc(d4_MAX_FLOOR_SIZE, sizeof(char *)),
	};
	
	return floor;
}


void d4_parse_file(char *filepath, d4_floor *floor) {
	FILE *file = fopen(filepath, "r");
	
	char *buffer = calloc(d4_MAX_FLOOR_SIZE, sizeof(char));
	
	while(fgets(buffer, d4_MAX_FLOOR_SIZE, file)) {
		buffer[strlen(buffer)-1] = '\0';
		floor->floor[floor->rows++] = buffer;
	
		buffer = calloc(d4_MAX_FLOOR_SIZE, sizeof(char));
	}
	
	floor->cols = strlen(floor->floor[0]);
	
	free(buffer);
}


int64_t d4_remove_all_rolls(d4_floor *floor, bool recursive) {
	int64_t total = 0;
	
	d4_removable removable;
	do {
		removable = (d4_removable){
			.length = 0,
			.positions = calloc(d4_MAX_FLOOR_SIZE, sizeof(d4_pos))
		};
	
		d4_get_removable_rolls(floor, &removable);
		d4_remove_rools(floor, &removable);
	
		total += removable.length;
	
		free(removable.positions);
	} while (recursive && removable.length);
	
	return total;
}


void d4_get_removable_rolls(d4_floor *floor, d4_removable *removable) {
	for (int row = 0; row < floor->rows; row++) {
		for (int col = 0; col < floor->cols; col++) {
			if (floor->floor[row][col] != '@') {
				continue;
			}
	
			if (d4_surrounds(floor, row, col) < 4) {
				removable->positions[removable->length++] =
				(d4_pos) {
					.row = row,
					.col = col,
				};
			}
		}
	}
}


int64_t d4_surrounds(d4_floor *floor, int64_t row, int64_t col) {
	int64_t total = 0;
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			if (row + i < 0 || row + i > floor->rows - 1) {
				continue;
			}
			if (col + j < 0 || col + j > floor->cols - 1) {
				continue;
			}
			if (i == 0 && j == 0) {
				continue;
			}
	
			if (floor->floor[row+i][col+j] == '@') {
				total++;
			}
		}
	}
	
	return total;
}


void d4_remove_rools(d4_floor *floor, d4_removable *removable) {
	for (int i = 0; i < removable->length; i++) {
		d4_pos curr = removable->positions[i];
		floor->floor[curr.row][curr.col] = '.';
	}
}

