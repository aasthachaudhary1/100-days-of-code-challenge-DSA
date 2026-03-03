#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isValid(char* s) {
    int len = strlen(s);
    
    // Stack using dynamic memory
    char *stack = (char*)malloc(len * sizeof(char));
    int top = -1;

    for(int i = 0; i < len; i++) {
        char ch = s[i];

        // If opening bracket → push
        if(ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        }
        else {
            // If stack empty → invalid
            if(top == -1) {
                free(stack);
                return false;
            }

            char topChar = stack[top--];

            // Check matching
            if((ch == ')' && topChar != '(') ||
               (ch == '}' && topChar != '{') ||
               (ch == ']' && topChar != '[')) {
                free(stack);
                return false;
            }
        }
    }

    // If stack empty → valid
    bool result = (top == -1);
    free(stack);
    return result;
}
