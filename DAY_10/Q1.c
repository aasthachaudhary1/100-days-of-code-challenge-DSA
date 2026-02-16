Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO

Example:
Input:
level

Output:
YES

Explanation: String reads same forwards and backwards

#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int l, r, flag = 1;

    // Read string
    scanf("%s", s);

    l = 0;
    r = strlen(s) - 1;

    // Two-pointer comparison
    while (l < r) {
        if (s[l] != s[r]) {
            flag = 0;
            break;
        }
        l++;
        r--;
    }

    // Output result
    if (flag)
        printf("YES");
    else
        printf("NO");

    return 0;
}
