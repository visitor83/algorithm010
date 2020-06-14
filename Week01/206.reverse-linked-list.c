/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head)
{
  struct ListNode *cur, *p, *tmp;

  if (!head || !head->next) {
    return head;
  }

  p = head;
  cur = NULL;
  while (p) {
    tmp = p;
    p = p->next;
    
    tmp->next = cur;
    cur = tmp;
  }
  return cur;
}