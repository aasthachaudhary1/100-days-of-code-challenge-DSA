Given an array of integers, rotate the array to the right by k positions.

Input:
- First line: integer n
- Second line: n integers
- Third line: integer k

Output:
- Print the rotated array

Example:
Input:
5
1 2 3 4 5
2


  #include <stdio.h>

int main() {
    int n, k;
    int a[100];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &k);

    k = k % n;   // handle k > n

    // rotate k times
    for (int i = 0; i < k; i++) {
        int last = a[n - 1];
        for (int j = n - 1; j > 0; j--) {
            a[j] = a[j - 1];
        }
        a[0] = last;
    }

    // print rotated array
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
