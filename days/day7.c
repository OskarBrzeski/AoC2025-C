#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utility.h"
#include "day7.h"


i64 day7part1(char *filepath) {
	d7_grid grid = d7_new_grid();

	d7_parse_file(filepath, &grid);
	i64 answer = d7_beam_splits(&grid);

	d7_free_grid(&grid);
	return answer;
}


i64 day7part2(char *filepath) {
	d7_grid grid = d7_new_grid();

	d7_parse_file(filepath, &grid);
	i64 answer = d7_beam_timelines(&grid);

	d7_free_grid(&grid);
	return answer;
}


d7_grid d7_new_grid(void) {
	d7_grid grid = {
		.rows = 0,
		.cols = 0,
		.grid = calloc(200, sizeof(char *)),
	};

	return grid;
}


void d7_free_grid(d7_grid *grid) {
	for (i64 i = 0; i < grid->rows; i++) {
		free(grid->grid[i]);
	}
	free(grid->grid);
}


void d7_parse_file(char *filepath, d7_grid *grid) {
	FILE *file = fopen(filepath, "r");

	const i64 BUFFER_SIZE = 200;
	char *buffer = calloc(BUFFER_SIZE, sizeof(char));
	
	while (fgets(buffer, BUFFER_SIZE, file)) {
		grid->grid[grid->rows++] = buffer;
		buffer = calloc(BUFFER_SIZE, sizeof(char));
	}
	grid->cols = strlen(grid->grid[0]);

	free(buffer);
	fclose(file);
}


i64 d7_beam_splits(d7_grid *grid) {
	i64 split_count = 0;

	bool *beam_cols = calloc(200, sizeof(bool));
	beam_cols[d7_find_start_col(grid)] = true;

	for (i64 row = 1; row < grid->rows; row++) {
		d7_progress_beams(grid, row, beam_cols, &split_count);
	}

	return split_count;
}


i64 d7_beam_timelines(d7_grid *grid) {
	i64 *beam_cols = calloc(200, sizeof(i64));
	beam_cols[d7_find_start_col(grid)] = 1;

	for (i64 row = 1; row < grid->rows; row++) {
		d7_progress_beams2(grid, row, beam_cols);
	}

	return d7_sum_timelines(beam_cols);
}


i64 d7_find_start_col(d7_grid *grid) {
	for (i64 col = 0; col < grid->cols; col++) {
		if (grid->grid[0][col] == 'S') return col;
	}
	return -1;
}


void d7_progress_beams(d7_grid *grid, i64 row, bool *beams, i64 *split_count) {
	for (i64 col = 0; col < grid->cols; col++) {
		if (beams[col] && grid->grid[row][col] == '^') {
			if (col > 0) beams[col-1] = true;
			beams[col] = false;
			beams[col+1] = true;
			(*split_count)++;
		}
	}
}


void d7_progress_beams2(d7_grid *grid, i64 row, i64 *beams) {
	for (i64 col = 0; col < grid->cols; col++) {
		if (beams[col] && grid->grid[row][col] == '^') {
			if (col > 0) beams[col-1] += beams[col];
			beams[col+1] += beams[col];
			beams[col] = 0;
		}
	}
}


i64 d7_sum_timelines(i64 *beams) {
	i64 total = 0;
	for (i64 i = 0; i < 200; i++) {
		total += beams[i];
	}
	return total;
}

