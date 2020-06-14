/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) 
{
  struct ListNode *slow, *fast;

  if (!head || !head->next) {
    return NULL;
  }

  slow = head;
  fast = head;
  /* have cycle ? */
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (fast == slow) {
      break;
    }
  }
  if (fast != slow) {
    return NULL;
  }
  if (fast == slow && fast == head && !fast->next) {
    return NULL;
  }

  //printf("%d \n", fast->val);
  fast = head;
  while (slow != fast) {
    slow = slow->next;
    fast = fast->next;
  }
  return fast;
}