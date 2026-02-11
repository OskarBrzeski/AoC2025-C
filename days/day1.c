#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "day1.h"


int32_t
day1part1(char *filepath) {
    d1_rotations rotations = d1_new_rotations();

    d1_parse_file(filepath, &rotations);

    int32_t answer = d1_simulate_dial(&rotations);
    d1_free_rotations(&rotations);
    return answer;
}


int32_t
day1part2(char *filepath) {
    d1_rotations rotations = d1_new_rotations();

    d1_parse_file(filepath, &rotations);

    int32_t answer = d1_simulate_dial2(&rotations);
    d1_free_rotations(&rotations);
    return answer;
}


d1_rotations
d1_new_rotations(void) {
    const int32_t ROTATIONSCAP = 5000;

    d1_rotations rotations = {
        .capacity = ROTATIONSCAP,
        .length = 0,
        .values = calloc(ROTATIONSCAP, sizeof(int32_t)),
    };

    return rotations;
}


void
d1_free_rotations(d1_rotations *rotations) {
    free(rotations->values);
}


void
d1_parse_file(char *filepath, d1_rotations *rotations) {
    FILE *file = fopen(filepath, "r");

    const int32_t BUFFER_SIZE = 1024;
    char *buffer = calloc(BUFFER_SIZE, sizeof(char));

    int32_t number = 0;
    while (fgets(buffer, BUFFER_SIZE, file)) {
        number += atoi(&buffer[1]);
        if (buffer[0] == 'L') {
            number = -number;
        }
        rotations->values[rotations->length++] = number;

        number = 0;
    }

    free(buffer);
    fclose(file);
}


int32_t
d1_simulate_dial(d1_rotations *rotations) {
    int32_t current_pos = 50;
    int32_t zero_count = 0;

    for (int i = 0; i < rotations->length; i++) {
        current_pos += rotations->values[i];

        while (current_pos < 0) {
            current_pos += 100;
        }
        while (current_pos > 99) {
            current_pos -= 100;
        }

        if (current_pos == 0) {
            zero_count++;
        }
    }

    return zero_count;
}


int32_t
d1_simulate_dial2(d1_rotations *rotations) {
    int32_t current_pos = 50;
    int32_t zero_count = 0;

    for (int i = 0; i < rotations->length; i++) {
        int32_t rot = rotations->values[i];
        if (rot < 0) {
            while (rot < 0) {
                current_pos--;
                if (current_pos < 0) {
                    current_pos += 100;
                }
                if (current_pos == 0) {
                    zero_count++;
                }
                rot++;
            }
        } else {
            while (rot > 0) {
                current_pos++;
                if (current_pos > 99) {
                    current_pos -= 100;
                }
                if (current_pos == 0) {
                    zero_count++;
                }
                rot--;
            }
        }
    }

    return zero_count;
}
