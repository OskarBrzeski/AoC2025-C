#include <stdio.h>
#include <stdlib.h>

#include "../utility.h"
#include "day1.h"


i64
day1part1(char *filepath) {
	d1_rotations rotations = d1_new_rotations();

	d1_parse_file(filepath, &rotations);
	i64 answer = d1_simulate_dial(&rotations);

	free(rotations.values);
	return answer;
}


i64
day1part2(char *filepath) {
	d1_rotations rotations = d1_new_rotations();

	d1_parse_file(filepath, &rotations);
	i64 answer = d1_simulate_dial2(&rotations);

	free(rotations.values);
	return answer;
}


d1_rotations
d1_new_rotations(void) {
	const i64 ROTATIONSCAP = 5000;

	d1_rotations rotations = {
		.length = 0,
		.values = calloc(ROTATIONSCAP, sizeof(i64)),
	};

	return rotations;
}


void
d1_parse_file(char *filepath, d1_rotations *rotations) {
	FILE *file = fopen(filepath, "r");

	const i64 BUFFER_SIZE = 1024;
	char *buffer = calloc(BUFFER_SIZE, sizeof(char));

	i64 number = 0;
	while (fgets(buffer, BUFFER_SIZE, file)) {
		number += atol(buffer + 1);
		if (buffer[0] == 'L') {
			number = -number;
		}
		rotations->values[rotations->length++] = number;

		number = 0;
	}

	free(buffer);
	fclose(file);
}


i64
d1_simulate_dial(d1_rotations *rotations) {
	i64 current_pos = 50;
	i64 zero_count = 0;

	for (int i = 0; i < rotations->length; i++) {
		current_pos += rotations->values[i];

		while (current_pos < 0) current_pos += 100;
		while (current_pos > 99) current_pos -= 100;

		if (current_pos == 0) zero_count++;
	}

	return zero_count;
}


i64
d1_simulate_dial2(d1_rotations *rotations) {
	i64 current_pos = 50;
	i64 zero_count = 0;

	for (int i = 0; i < rotations->length; i++) {
		i64 rot = rotations->values[i];
		if (rot < 0) {
			while (rot < 0) {
				current_pos--;
				if (current_pos < 0) current_pos += 100;
				if (current_pos == 0) zero_count++;
				rot++;
			}
		} else {
			while (rot > 0) {
				current_pos++;
				if (current_pos > 99) current_pos -= 100;
				if (current_pos == 0) zero_count++;
				rot--;
			}
		}
	}

	return zero_count;
}

