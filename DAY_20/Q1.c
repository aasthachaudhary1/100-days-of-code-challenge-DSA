Given an array of integers, count the number of subarrays whose sum is equal to zero.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the count of subarrays having sum zero

Example:
Input:
6
1 -1 2 -2 3 -3

Output:
6

  #include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefix = 0;
    int count = 0;
    int size = 200001;
    int *freq = (int*)calloc(size, sizeof(int));
    
    int offset = 100000;  
    freq[offset] = 1;    

    for(int i = 0; i < n; i++) {
        prefix += arr[i];

        if(freq[prefix + offset] > 0) {
            count += freq[prefix + offset];
        }

        freq[prefix + offset]++;
    }

    printf("%d", count);

    free(freq);
    return 0;
}
