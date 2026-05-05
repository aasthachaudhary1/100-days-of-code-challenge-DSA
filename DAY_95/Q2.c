#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int maximumGap(int* nums, int numsSize) {
    if (numsSize < 2) return 0;

    int minVal = INT_MAX, maxVal = INT_MIN;

    // Step 1: Find min and max
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < minVal) minVal = nums[i];
        if (nums[i] > maxVal) maxVal = nums[i];
    }

    if (minVal == maxVal) return 0;

    // Step 2: Calculate bucket size and count
    int bucketSize = (maxVal - minVal) / (numsSize - 1);
    if (bucketSize == 0) bucketSize = 1;

    int bucketCount = (maxVal - minVal) / bucketSize + 1;

    int* bucketMin = (int*)malloc(bucketCount * sizeof(int));
    int* bucketMax = (int*)malloc(bucketCount * sizeof(int));

    for (int i = 0; i < bucketCount; i++) {
        bucketMin[i] = INT_MAX;
        bucketMax[i] = INT_MIN;
    }

    // Step 3: Fill buckets
    for (int i = 0; i < numsSize; i++) {
        int idx = (nums[i] - minVal) / bucketSize;
        if (nums[i] < bucketMin[idx]) bucketMin[idx] = nums[i];
        if (nums[i] > bucketMax[idx]) bucketMax[idx] = nums[i];
    }

    // Step 4: Find max gap
    int maxGap = 0;
    int prevMax = minVal;

    for (int i = 0; i < bucketCount; i++) {
        if (bucketMin[i] == INT_MAX) continue;

        int gap = bucketMin[i] - prevMax;
        if (gap > maxGap) maxGap = gap;

        prevMax = bucketMax[i];
    }

    free(bucketMin);
    free(bucketMax);

    return maxGap;
}
