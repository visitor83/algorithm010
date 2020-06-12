/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) 
{
  struct ListNode *slow, *fast;

  if (!head || !head->next) {
    return false;
  }

  slow = head;
  fast = head->next;

  while (fast != NULL   &&  fast != slow) {
    slow = slow->next;
    fast = fast->next ==  NULL ? NULL : fast->next->next;
  }
  
  return fast == slow ? true : false;
}