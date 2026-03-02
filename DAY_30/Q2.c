#include <stdlib.h>

int getLength(struct ListNode* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int len1 = getLength(l1);
    int len2 = getLength(l2);

    int* stack1 = (int*)malloc(len1 * sizeof(int));
    int* stack2 = (int*)malloc(len2 * sizeof(int));

    int i = 0;
    while (l1) {
        stack1[i++] = l1->val;
        l1 = l1->next;
    }

    i = 0;
    while (l2) {
        stack2[i++] = l2->val;
        l2 = l2->next;
    }

    int top1 = len1 - 1;
    int top2 = len2 - 1;
    int carry = 0;
    struct ListNode* result = NULL;

    while (top1 >= 0 || top2 >= 0 || carry) {
        int sum = carry;

        if (top1 >= 0) sum += stack1[top1--];
        if (top2 >= 0) sum += stack2[top2--];

        carry = sum / 10;

        struct ListNode* newNode = createNode(sum % 10);
        newNode->next = result;
        result = newNode;
    }

    free(stack1);
    free(stack2);

    return result;
}
