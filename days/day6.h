#include "../utility.h"

typedef enum {
	d6_ADD,
	d6_MUL,
} d6_op;

typedef struct {
	i64 rows;
	i64 cols;
	i64 *nums[4];
	d6_op *ops;
} d6_nums;

typedef struct {
	i64 rows;
	i64 cols;
	char **buffer;
} d6_buffer;

i64 day6part1(char *filepath);
i64 day6part2(char *filepath);

d6_nums d6_new_nums(void);
void d6_free_nums(d6_nums *nums);
void d6_parse_file(char *filepath, d6_nums *nums);
void d6_parse_num_row(char *buffer, d6_nums *nums, i64 row);
void d6_parse_op_row(char *buffer, d6_nums *nums);

i64 d6_sum_solutions(d6_nums *nums);
i64 d6_column_result(d6_nums *nums, i64 col);

d6_buffer d6_new_buffer(void);
void d6_free_buffer(d6_buffer *buffer);
void d6_parse_file2(char *filepath, d6_buffer *buffer);

i64 d6_sum_soltions2(d6_buffer *buffer);
d6_op d6_get_op(d6_buffer *buffer, i64 col);
i64 d6_get_num(d6_buffer *buffer, i64 col);
bool d6_is_blank_col(d6_buffer *buffer, i64 col);

