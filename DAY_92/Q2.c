#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* nums, int left, int right) {
    // Random pivot selection
    int pivotIndex = left + rand() % (right - left + 1);
    swap(&nums[pivotIndex], &nums[right]);

    int pivot = nums[right];
    int i = left;

    for (int j = left; j < right; j++) {
        if (nums[j] <= pivot) {
            swap(&nums[i], &nums[j]);
            i++;
        }
    }
    swap(&nums[i], &nums[right]);
    return i;
}

int quickSelect(int* nums, int left, int right, int k_smallest) {
    if (left == right)
        return nums[left];

    int pivotIndex = partition(nums, left, right);

    if (pivotIndex == k_smallest)
        return nums[pivotIndex];
    else if (pivotIndex < k_smallest)
        return quickSelect(nums, pivotIndex + 1, right, k_smallest);
    else
        return quickSelect(nums, left, pivotIndex - 1, k_smallest);
}

int findKthLargest(int* nums, int numsSize, int k) {
    srand(time(NULL)); // seed random
    return quickSelect(nums, 0, numsSize - 1, numsSize - k);
}
