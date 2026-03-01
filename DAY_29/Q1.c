Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30

Explanation:
Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.

  #include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Rotate linked list right by k places
struct Node* rotateRight(struct Node* head, int k)
{
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    struct Node* temp = head;
    int count = 1;

    // Count total nodes
    while (temp->next != NULL)
    {
        temp = temp->next;
        count++;
    }

    // Make it circular
    temp->next = head;

    // Reduce k if greater than count
    k = k % count;

    int steps = count - k;

    struct Node* newTail = head;

    // Move to (n-k)th node
    for (int i = 1; i < steps; i++)
    {
        newTail = newTail->next;
    }

    struct Node* newHead = newTail->next;

    // Break circular link
    newTail->next = NULL;

    return newHead;
}

// Print linked list
void printList(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int n, value, k;
    struct Node *head = NULL, *temp = NULL, *newNode;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        newNode = createNode(value);

        if (head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    scanf("%d", &k);

    head = rotateRight(head, k);

    printList(head);

    return 0;
}
