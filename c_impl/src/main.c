#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INPUT_INIT_SIZE 32

int parseInteger(int **input, size_t *input_size, size_t *input_capacity, char *argv) {
    int value = atoi(argv);
    if(value == 0 && argv[0] != '0') {
        return 1;
    }

    if(*input_size == *input_capacity) {
        int *newBuf = malloc(sizeof(int)*(*input_capacity)*2);
        memcpy(newBuf, *input, sizeof(int)*(*input_capacity));
        free(*input);
        *input_capacity *= 2;
        *input = newBuf;
    }
    (*input)[(*input_size)++] = value;
    return 0;
}

void findLocalMaxima(int *input, int size) {
    int consecutive = 0;
    for(size_t i = 1; i + 1 < size; ++i) {
        if(input[i-1] <= input[i] && input[i] >= input[i+1]) {
            if(consecutive == 0) {
                printf("%d ", input[i]);
                consecutive = 1;
            }
        } else {
            consecutive = 0;
        }
    }
    printf("\n");
}

int main(int argc, char **argv) {
    int *input = (int*)malloc(sizeof(int) * INPUT_INIT_SIZE);
    size_t input_size = 0;
    size_t input_capacity = INPUT_INIT_SIZE;

    --argc; ++argv;
    while(argc > 0) {
        if(parseInteger(&input, &input_size, &input_capacity, argv[0]) != 0) {
            free(input);
            return 1;
        }
        --argc; ++argv;
    }

    findLocalMaxima(input, input_size);

    free(input);
    return 0;
}
