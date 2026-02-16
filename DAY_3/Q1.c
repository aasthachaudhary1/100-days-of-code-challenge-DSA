Implement linear search to find key k in an array. Count and display the number of comparisons performed.

Input:
- First line: integer n (array size)
- Second line: n space-separated integers
- Third line: integer k (key to search)

Output:
- Line 1: "Found at index i" OR "Not Found"
Line 2: "Comparisons = c"

Example:
Input:
5
10 20 30 40 50
30

Output:
Found at index 2
Comparisons = 3

Explanation: Compared with 10, 20, 30 (found at index 2 with 3 comparisons)

#include <stdio.h>

int main() {
    int n, k;
    int a[100];
    int found = 0;
    int comparisons = 0;

    // Read array size
    scanf("%d", &n);

    // Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Read key to search
    scanf("%d", &k);

    // Linear search
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (a[i] == k) {
            printf("Found at index %d\n", i);
            found = 1;
            break;
        }
    }

    // If not found
    if (!found) {
        printf("Not Found\n");
    }

    // Print comparisons
    printf("Comparisons = %d", comparisons);

    return 0;
}
