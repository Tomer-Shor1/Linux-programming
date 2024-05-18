
/*
    - Wrriten by Tomer Shor. 
    - 15/05/2024

    
    This file includes 3 implementations of min sub array problem.
    The purpose of this file is to show the diference?? of running times using GPROF.
    To run the example: $ make run
    In order to view the stats open analysis.txt file.
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_random_array(int *arr, int size, unsigned int seed) {
    srand(seed);
    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % 100) - 25; // Random integers between -25 and 74
    }
}


// n^3 solution.
int max_subarray_sum_n3(int *arr, int size) {
    int max_sum = arr[0];
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            int current_sum = 0;
            for (int k = i; k <= j; k++) {
                current_sum += arr[k];
            }
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
        }
    }
    return max_sum;
}



int max_subarray_sum_n2(int *arr, int size) {
    int max_sum = arr[0];
    for (int i = 0; i < size; i++) {
        int current_sum = 0;
        for (int j = i; j < size; j++) {
            current_sum += arr[j];
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
        }
    }
    return max_sum;
}


// O(n) implementation.
int max_subarray_sum_n(int *arr, int size) {
    int max_sum = arr[0];
    int current_sum = arr[0];
    for (int i = 1; i < size; i++) {
        current_sum = (current_sum > 0) ? current_sum + arr[i] : arr[i];
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }
    return max_sum;
}



int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <seed> <size>\n", argv[0]);
        return 1;
    }

    unsigned int seed = atoi(argv[1]);
    int size = atoi(argv[2]);

    int *arr = (int *)malloc(size * sizeof(int));
    if (!arr) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    generate_random_array(arr, size, seed);

    int max_sum_n3 = max_subarray_sum_n3(arr, size);
    int max_sum_n2 = max_subarray_sum_n2(arr, size);
    int max_sum_n = max_subarray_sum_n(arr, size);

    printf("Array of size %d generated with seed %d\n", size, seed);
    printf("Max Subarray Sum (O(n^3)): %d\n", max_sum_n3);
    printf("Max Subarray Sum (O(n^2)): %d\n", max_sum_n2);
    printf("Max Subarray Sum (O(n)): %d\n", max_sum_n);

    free(arr);
    return 0;
}









