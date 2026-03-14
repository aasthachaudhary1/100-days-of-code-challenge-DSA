Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10
  #include <stdio.h>

#define MAX 100

int queue[MAX];
int stack[MAX];
int front = 0, rear = -1;
int top = -1;

int main() {
    int n, i, x;

    scanf("%d", &n);

    /* Enqueue elements */
    for(i = 0; i < n; i++) {
        scanf("%d", &x);
        queue[++rear] = x;
    }

    /* Move queue to stack */
    while(front <= rear) {
        stack[++top] = queue[front++];
    }

    /* Pop stack (reversed order) */
    while(top >= 0) {
        printf("%d ", stack[top--]);
    }

    return 0;
}
