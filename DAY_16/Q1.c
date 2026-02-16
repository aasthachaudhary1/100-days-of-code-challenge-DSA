 Given an array of integers, count the frequency of each distinct element and print the result.

Input:
- First line: integer n (size of array)
- Second line: n integers

Output:
- Print each element followed by its frequency in the format element:count

Example:
Input:
5
1 2 2 3 1

Output:
1:2 2:2 3:1

  #include <stdio.h>

int main() {
    int n;
    int a[100];
    int visited[100] = {0};

    // Read size of array
    scanf("%d", &n);

    // Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Count frequencies
    for (int i = 0; i < n; i++) {
        if (visited[i] == 1)
            continue;

        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                count++;
                visited[j] = 1;
            }
        }
        printf("%d:%d ", a[i], count);
    }

    return 0;
}
