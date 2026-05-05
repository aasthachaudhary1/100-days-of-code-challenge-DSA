#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort
int compare(const void* a, const void* b) {
    return (*(int**)a)[0] - (*(int**)b)[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    
    // Step 1: Sort intervals based on start time
    qsort(intervals, intervalsSize, sizeof(int*), compare);
    
    int** result = (int**)malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));
    
    int idx = 0;

    // Initialize first interval
    result[idx] = (int*)malloc(2 * sizeof(int));
    result[idx][0] = intervals[0][0];
    result[idx][1] = intervals[0][1];
    (*returnColumnSizes)[idx] = 2;

    for (int i = 1; i < intervalsSize; i++) {
        // Overlap condition
        if (intervals[i][0] <= result[idx][1]) {
            // Merge
            if (intervals[i][1] > result[idx][1]) {
                result[idx][1] = intervals[i][1];
            }
        } else {
            // New interval
            idx++;
            result[idx] = (int*)malloc(2 * sizeof(int));
            result[idx][0] = intervals[i][0];
            result[idx][1] = intervals[i][1];
            (*returnColumnSizes)[idx] = 2;
        }
    }

    *returnSize = idx + 1;
    return result;
}
