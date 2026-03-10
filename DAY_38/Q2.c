#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    
    *returnSize = numsSize - k + 1;
    int* result = (int*)malloc((*returnSize) * sizeof(int));
    
    int* deque = (int*)malloc(numsSize * sizeof(int));
    int front = 0, rear = -1;

    int index = 0;

    for(int i = 0; i < numsSize; i++) {

        // Remove elements outside window
        if(front <= rear && deque[front] <= i - k)
            front++;

        // Remove smaller elements
        while(front <= rear && nums[deque[rear]] < nums[i])
            rear--;

        // Add current index
        deque[++rear] = i;

        // Store result when window size reached
        if(i >= k - 1)
            result[index++] = nums[deque[front]];
    }

    free(deque);
    return result;
}
