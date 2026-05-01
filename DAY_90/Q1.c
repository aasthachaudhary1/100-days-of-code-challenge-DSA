#include <stdio.h>
#include <limits.h>

// Helper function to check if we can split into k subarrays
int canSplit(int* nums, int numsSize, int k, int maxSum) {
    int count = 1;  // at least one subarray
    int currSum = 0;

    for (int i = 0; i < numsSize; i++) {
        if (currSum + nums[i] <= maxSum) {
            currSum += nums[i];
        } else {
            count++;
            currSum = nums[i];
            if (count > k) return 0;
        }
    }
    return 1;
}

int splitArray(int* nums, int numsSize, int k) {
    int low = 0, high = 0;

    // Initialize low and high
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > low)
            low = nums[i];   // max element
        high += nums[i];     // total sum
    }

    int result = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canSplit(nums, numsSize, k, mid)) {
            result = mid;
            high = mid - 1;  // try smaller
        } else {
            low = mid + 1;   // need larger sum
        }
    }

    return result;
}
