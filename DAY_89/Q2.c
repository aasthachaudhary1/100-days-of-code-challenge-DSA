#include <stdio.h>

// Function to check if we can ship within given days
int canShip(int* weights, int size, int days, int capacity) {
    int requiredDays = 1;
    int currentLoad = 0;

    for (int i = 0; i < size; i++) {
        if (currentLoad + weights[i] > capacity) {
            requiredDays++;
            currentLoad = 0;
        }
        currentLoad += weights[i];
    }

    return requiredDays <= days;
}

int shipWithinDays(int* weights, int weightsSize, int days) {
    int left = weights[0], right = 0;

    // Find max and sum
    for (int i = 0; i < weightsSize; i++) {
        if (weights[i] > left)
            left = weights[i];
        right += weights[i];
    }

    int result = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canShip(weights, weightsSize, days, mid)) {
            result = mid;
            right = mid - 1;  // try smaller capacity
        } else {
            left = mid + 1;   // increase capacity
        }
    }

    return result;
}
