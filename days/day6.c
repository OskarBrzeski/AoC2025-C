#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utility.h"
#include "day6.h"


i64 day6part1(char *filepath) {
	d6_nums nums = d6_new_nums();

	d6_parse_file(filepath, &nums);
	i64 answer = d6_sum_solutions(&nums);

	d6_free_nums(&nums);
	return answer;
}


i64 day6part2(char *filepath) {
	d6_buffer buffer = d6_new_buffer();

	d6_parse_file2(filepath, &buffer);
	i64 answer = d6_sum_soltions2(&buffer);

	d6_free_buffer(&buffer);
	return answer;
}


d6_nums d6_new_nums(void) {
	const i64 MAX_NUMS = 2000;

	d6_nums nums = {
		.rows = 0,
		.cols = 0,
		.nums = {
			calloc(MAX_NUMS, sizeof(i64)),
			calloc(MAX_NUMS, sizeof(i64)),
			calloc(MAX_NUMS, sizeof(i64)),
			calloc(MAX_NUMS, sizeof(i64)),
		},
		.ops = calloc(MAX_NUMS, sizeof(d6_op)),
	};

	return nums;
}


void d6_free_nums(d6_nums *nums) {
	free(nums->nums[0]);
	free(nums->nums[1]);
	free(nums->nums[2]);
	free(nums->nums[3]);
	free(nums->ops);
}


void d6_parse_file(char *filepath, d6_nums *nums) {
	FILE *file = fopen(filepath, "r");

	const i64 LINE_LENGTH = 5000;
	char *buffer = calloc(LINE_LENGTH, sizeof(char));

	while (fgets(buffer, LINE_LENGTH, file)) {
		if (buffer[0] == '+' || buffer[0] == '*') {
			d6_parse_op_row(buffer, nums);
		} else {
			d6_parse_num_row(buffer, nums, nums->rows++);
		}

		u_reset_buffer(buffer, LINE_LENGTH);
	}

	free(buffer);
	fclose(file);
}


void d6_parse_num_row(char *buffer, d6_nums *nums, i64 row) {
	bool num = false;
	i64 length = 0;
	i64 current = 0;

	i64 buffer_len = strlen(buffer);
	for (i64 i = 0; i < buffer_len; i++) {
		if (!num && buffer[i] != ' ') {
			num = true;
		}

		if (num && buffer[i] != ' ' && buffer[i] != '\n') {
			current = current * 10 + (buffer[i] - 48);
		}

		if (num && (buffer[i] == ' ' || buffer[i] == '\n')) {
			num = false;
			nums->nums[row][length++] = current;
			current = 0;
		}
	}
}


void d6_parse_op_row(char *buffer, d6_nums *nums) {
	i64 length = 0;

	i64 buffer_len = strlen(buffer);
	for (i64 i = 0; i < buffer_len; i++) {
		switch (buffer[i]) {
		case '+':
			nums->ops[length++] = d6_ADD;
			break;
		case '*':
			nums->ops[length++] = d6_MUL;
			break;
		default:
			continue;
		}
	}

	nums->cols = length;
}


i64 d6_sum_solutions(d6_nums *nums) {
	i64 total = 0;

	for (i64 i = 0; i < nums->cols; i++) {
		total += d6_column_result(nums, i);
	}

	return total;
}


i64 d6_column_result(d6_nums *nums, int64_t col) {
	i64 result = 0;

	for (i64 i = 0; i < nums->rows; i++) {
		switch (nums->ops[col]) {
		case d6_ADD:
			result += nums->nums[i][col];
			break;
		case d6_MUL:
			result = u_max(result, 1);
			result *= nums->nums[i][col];
			break;
		}
	}
	
	return result;
}


d6_buffer d6_new_buffer(void) {
	d6_buffer buffer = {
		.rows = 0,
		.cols = 0,
		.buffer = calloc(10, sizeof(char *)),
	};

	return buffer;
}


void d6_free_buffer(d6_buffer *buffer) {
	for (i64 i = 0; i < buffer->rows; i++) {
		free(buffer->buffer[i]);
	}
	free(buffer->buffer);
}


void d6_parse_file2(char *filepath, d6_buffer *buffer) {
	FILE *file = fopen(filepath, "r");

	const i64 LINE_LEN = 5000;
	char *buf = calloc(LINE_LEN, sizeof(char));

	while (fgets(buf, LINE_LEN, file)) {
		buffer->buffer[buffer->rows++] = buf;

		buf = calloc(LINE_LEN, sizeof(char));
	}
	buffer->cols = strlen(buffer->buffer[0]);

	free(buf);
	fclose(file);
}


i64 d6_sum_soltions2(d6_buffer *buffer) {
	i64 total = 0;

	bool new_num = true;
	d6_op op;
	i64 current = 0;
	for (i64 col = 0; col < buffer->cols; col++) {
		if (d6_is_blank_col(buffer, col)) {
			total += current;
			current = 0;
			new_num = true;
			continue;
		}

		if (new_num) {
			op = d6_get_op(buffer, col);
			new_num = false;
		}

		if (!new_num) {
			i64 num = d6_get_num(buffer, col);
			switch (op) {
			case d6_ADD:
				current += num;
				break;
			case d6_MUL:
				current = u_max(current, 1);
				current *= num;
				break;
			}
		}
	}

	return total;
}


d6_op d6_get_op(d6_buffer *buffer, i64 col) {
	char current = buffer->buffer[buffer->rows-1][col];
	if (current == '+') return d6_ADD;
	if (current == '*') return d6_MUL;

	assert(1 == 0);
}


i64 d6_get_num(d6_buffer *buffer, i64 col) {
	i64 num = 0;

	for (i64 row = 0; row < buffer->rows - 1; row++) {
		char current = buffer->buffer[row][col];

		if (current == ' ') continue;
		num = num * 10 + (current - 48);
	}

	return num;
}


bool d6_is_blank_col(d6_buffer *buffer, i64 col) {
	for (i64 row = 0; row < buffer->rows - 1; row++) {
		char current = buffer->buffer[row][col];
		if (current != ' ' && current != '\n') return false;
	}
	return true;
}

