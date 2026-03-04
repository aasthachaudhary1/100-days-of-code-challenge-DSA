#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *stack;
    int *minStack;
    int top;
    int capacity;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->capacity = 10000;  // max size (can adjust)
    obj->stack = (int*)malloc(obj->capacity * sizeof(int));
    obj->minStack = (int*)malloc(obj->capacity * sizeof(int));
    obj->top = -1;
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    obj->top++;
    obj->stack[obj->top] = val;
    
    if (obj->top == 0)
        obj->minStack[obj->top] = val;
    else {
        int currentMin = obj->minStack[obj->top - 1];
        obj->minStack[obj->top] = (val < currentMin) ? val : currentMin;
    }
}

void minStackPop(MinStack* obj) {
    if (obj->top >= 0)
        obj->top--;
}

int minStackTop(MinStack* obj) {
    return obj->stack[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return obj->minStack[obj->top];
}

void minStackFree(MinStack* obj) {
    free(obj->stack);
    free(obj->minStack);
    free(obj);
}
