/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool hasCycle2(struct ListNode *head) 
{

    struct ListNode * fast, *slow;
    if (!head || !head->next) {
        return false;
    }

    fast = head; slow = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }    

    return false;
}

bool hasCycle2(struct ListNode *head) 
{
    struct ListNode * slow, * fast;

    if (!head || !head->next) {
        return false;
    }

    slow = head;
    fast = head->next;
    while (slow != fast) {
        if (!fast || !fast->next) {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }    

    return true;
}

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