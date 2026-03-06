 Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.

  #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return 0;
    }
    struct node *temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int evaluatePostfix(char *exp) {
    char *token = strtok(exp, " ");

    while (token != NULL) {
        
        if (isdigit(token[0]) || (token[0]=='-' && isdigit(token[1]))) {
            push(atoi(token));
        }
        else {
            int b = pop();
            int a = pop();
            int res;

            switch(token[0]) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
            }

            push(res);
        }

        token = strtok(NULL, " ");
    }

    return pop();
}

int main() {
    char exp[100];

    fgets(exp, sizeof(exp), stdin);
    exp[strcspn(exp, "\n")] = '\0';

    printf("%d", evaluatePostfix(exp));

    return 0;
}
