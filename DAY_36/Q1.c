Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20

Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order. 


  #include <stdio.h>

int main()
{
    int n, m;
    scanf("%d", &n);

    int q[n];
    int front = 0, rear = -1;

    // Enqueue elements
    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);

        rear = (rear + 1) % n;
        q[rear] = x;
    }

    // Number of dequeue operations
    scanf("%d", &m);

    // Dequeue operations
    for(int i = 0; i < m; i++)
    {
        front = (front + 1) % n;
    }

    // Display queue
    int i = front;
    do
    {
        printf("%d ", q[i]);
        i = (i + 1) % n;
    }
    while(i != (rear + 1) % n);

    return 0;
}
