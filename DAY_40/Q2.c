#include <stdlib.h>

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    
    int* result = (int*)calloc(temperaturesSize, sizeof(int));
    int* stack = (int*)malloc(sizeof(int) * temperaturesSize);
    
    int top = -1;

    for(int i = 0; i < temperaturesSize; i++) {

        while(top >= 0 && temperatures[i] > temperatures[stack[top]]) {
            int prevIndex = stack[top--];
            result[prevIndex] = i - prevIndex;
        }

        stack[++top] = i;
    }

    *returnSize = temperaturesSize;

    free(stack);
    return result;
}
