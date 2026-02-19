#include "../utility.h"

typedef struct {
	i64 rows;
	i64 cols;
	char **grid;
} d7_grid;

i64 day7part1(char *filepath);
i64 day7part2(char *filepath);

d7_grid d7_new_grid(void);
void d7_free_grid(d7_grid *grid);
void d7_parse_file(char *filepath, d7_grid *grid);

i64 d7_beam_splits(d7_grid *grid);
i64 d7_beam_timelines(d7_grid *grid);
i64 d7_find_start_col(d7_grid *grid);
void d7_progress_beams(d7_grid *grid, i64 row, bool *beams, i64 *split_count);
void d7_progress_beams2(d7_grid *grid, i64 row, i64 *beams);
i64 d7_sum_timelines(i64 *beams);

