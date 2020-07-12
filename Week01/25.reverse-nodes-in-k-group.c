/*

给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

 

示例：

给你这个链表：1->2->3->4->5

当 k = 2 时，应当返回: 2->1->4->3->5

当 k = 3 时，应当返回: 3->2->1->4->5
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool IsEnough(struct ListNode *nh, int k, struct ListNode **next)
{
    struct ListNode *cur = nh;

    while (cur && k) {
        cur = cur->next;
        k--;
    }
    if (!cur && k) {
        *next = NULL;
        return false;
    }
    *next = cur;
    return true;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k)
{
    struct ListNode *nxth, *cur, *tail, dmy, *tmp;
    // terminator
   if (!head || !head->next){
       return head;
   }

   int step = k;

   // remain list elem is not enough
   if (!IsEnough(head, k, &nxth)) {
       printf("------------\n");
       return head;
   } else {
       tail = head;

       dmy.next = NULL;
       cur = head;
       while (step--) {
           tmp = cur->next;
           cur->next = dmy.next;
           dmy.next = cur;

           cur = tmp;
           if (!cur) {
               break;
           }
       }
   }
   if (nxth) {
        printf("nxth %d\n", nxth->val);
   }
   // revert link
   tail->next = reverseKGroup (nxth, k );
   return  dmy.next;
}