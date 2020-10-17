
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *slow, *fast;
    bool is_cycle = false;
    int pos = -1;

    if (!head) {
        return head;
    }
    slow = head;
    fast = head;

    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            is_cycle = true;
            break;
        }
    }
    if (!is_cycle) {
        printf(" no cy\n");
        return NULL;
    }

    fast = head;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}