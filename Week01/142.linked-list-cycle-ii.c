/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
 好的写法*/

 struct ListNode *detectCycle2(struct ListNode *head) 
{
    struct ListNode * fast, *slow;

    if (!head || !head->next) {
        return false;
    }

    fast = head; 
    slow = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }    
    if (fast == NULL || fast->next == NULL) {
        return NULL;
    }

    struct ListNode *p1 = head, *p2 = slow;
    while (p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}

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