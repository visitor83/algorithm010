/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    /* 两个升序链表，合并*/
    struct ListNode  dummy, *ptail;
    bool anull = false, bnull = false;

    dummy.next = NULL;
    ptail = &dummy;
    while (l1 != NULL || l2 != NULL) {
        //l1 && l2;
        int a = l1 == NULL ?  anull = true  : l1->val;
        int b = l2 == NULL ?  bnull = true  : l2->val;

        if (l2 && (a > b || anull)) {
            ptail->next =  l2;
            ptail = l2;
            l2 = l2->next;
        }
        
        if (l1 && (a <= b || bnull))
        {
            ptail->next =  l1;
            ptail = l1;
            l1 = l1->next;
        }
    }

    return dummy.next;

}