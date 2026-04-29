#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int canPlace(int* position, int positionSize, int m, int dist) {
    int count = 1;
    int last = position[0];

    for (int i = 1; i < positionSize; i++) {
        if (position[i] - last >= dist) {
            count++;
            last = position[i];

            if (count >= m) {
                return 1;
            }
        }
    }

    return 0;
}

int maxDistance(int* position, int positionSize, int m) {
    qsort(position, positionSize, sizeof(int), compare);

    int left = 1;
    int right = position[positionSize - 1] - position[0];
    int ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canPlace(position, positionSize, m, mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return ans;
}
