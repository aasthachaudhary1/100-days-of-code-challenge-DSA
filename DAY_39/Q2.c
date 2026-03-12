#include <stdlib.h>

typedef struct {
    int num;
    int freq;
} Pair;

int compare(const void* a, const void* b) {
    Pair* p1 = (Pair*)a;
    Pair* p2 = (Pair*)b;
    return p2->freq - p1->freq;   // descending order
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    
    Pair arr[numsSize];
    int unique = 0;

    // Count frequency
    for(int i = 0; i < numsSize; i++) {
        int found = 0;

        for(int j = 0; j < unique; j++) {
            if(arr[j].num == nums[i]) {
                arr[j].freq++;
                found = 1;
                break;
            }
        }

        if(!found) {
            arr[unique].num = nums[i];
            arr[unique].freq = 1;
            unique++;
        }
    }

    // Sort by frequency
    qsort(arr, unique, sizeof(Pair), compare);

    // Prepare result
    int* result = (int*)malloc(k * sizeof(int));

    for(int i = 0; i < k; i++) {
        result[i] = arr[i].num;
    }

    *returnSize = k;
    return result;
}
