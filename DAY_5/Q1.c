A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

Input:
- First line: integer p (number of entries in server log 1)
- Second line: p sorted integers representing arrival times from server 1
- Third line: integer q (number of entries in server log 2)
- Fourth line: q sorted integers representing arrival times from server 2)

Output:
- Print a single line containing all arrival times in chronological order, separated by spaces

Example:
Input:
5
10 20 30 50 70
4
15 25 40 60

Output:
10 15 20 25 30 40 50 60 70

Explanation: Compare the next unprocessed arrival time from both logs and append the earlier one to the final log until all entries are processed

#include <stdio.h>

int main() {
    int p, q;
    int a[100], b[100], c[200];
    int i = 0, j = 0, k = 0;

    // Read size and elements of server log 1
    scanf("%d", &p);
    for (i = 0; i < p; i++) {
        scanf("%d", &a[i]);
    }

    // Read size and elements of server log 2
    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        scanf("%d", &b[i]);
    }

    i = 0;
    j = 0;

    // Merge both sorted logs
    while (i < p && j < q) {
        if (a[i] <= b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }

    // Copy remaining elements of log 1
    while (i < p) {
        c[k++] = a[i++];
    }

    // Copy remaining elements of log 2
    while (j < q) {
        c[k++] = b[j++];
    }

    // Print merged chronological log
    for (i = 0; i < k; i++) {
        printf("%d ", c[i]);
    }

    return 0;
}
