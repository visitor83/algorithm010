/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int GetLength(struct ListNode *cur) {
    int cnt = 0;
    while (cur != NULL) {
        cur = cur->next;
        cnt++;
    }
    return cnt;
}
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int al = GetLength(headA), bl = GetLength(headB);
    struct ListNode *pa = headA, *pb = headB;
    int d = 0;

    d =  al - bl;
    if (bl > al) {
        pa = headB; pb = headA;
        d = bl - al;
    }

    while (d-- && pa != NULL) {
        pa = pa->next;
    }

    while (pa != NULL && pb != NULL) {
        if (pa == pb) {
            return pa;
        }
        pa = pa->next;
        pb = pb->next;
    }
    return NULL;
}

/// hashmap
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int GetLength(struct ListNode *cur) {
    int cnt = 0;
    while (cur != NULL) {
        cur = cur->next;
        cnt++;
    }
    return cnt;
}
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int al = GetLength(headA), bl = GetLength(headB);
    struct ListNode *pa = headA, *pb = headB;
    int d = 0;

    d =  al - bl;
    if (bl > al) {
        pa = headB; pb = headA;
        d = bl - al;
    }

    while (d-- && pa != NULL) {
        pa = pa->next;
    }

    while (pa != NULL && pb != NULL) {
        if (pa == pb) {
            return pa;
        }
        pa = pa->next;
        pb = pb->next;
    }
    return NULL;
}