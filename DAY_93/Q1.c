/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* insertionSortList(struct ListNode* head) {
    if (!head || !head->next) return head;

    // Dummy node for sorted list
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = NULL;

    struct ListNode* curr = head;

    while (curr) {
        struct ListNode* nextNode = curr->next;

        // Find position in sorted list
        struct ListNode* prev = &dummy;
        while (prev->next && prev->next->val < curr->val) {
            prev = prev->next;
        }

        // Insert current node
        curr->next = prev->next;
        prev->next = curr;

        // Move to next node
        curr = nextNode;
    }

    return dummy.next;
}
