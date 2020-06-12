struct ListNode* swapPairs(struct ListNode* head)
{
    struct ListNode * slow, *fast, *newh, *cur;
    struct ListNode *l1, *l2, *tail;
    struct ListNode dmy;
    int loop = 0;

    if (!head || !head->next) {
      return head;
    }
    
    dmy.next = NULL;
    slow = head;
    fast = head->next;
    newh = NULL;
    tail = NULL;
    while (fast != NULL)  {
        l1 = slow;
        l2 = fast;

        //printf("loop %d, %d\n", loop++, fast->val);
        cur = fast->next;

        l1->next = newh;
        newh = l1;   
        l2->next = newh;
        newh = l2;

        if (!dmy.next) {
          dmy.next = l2;
        }

        if (!tail) {
          tail = l1;
        } else {
          tail->next = l2;
          tail = l1;
        }
        newh = NULL;
        
        slow = cur;
        fast = cur == NULL ? NULL : cur->next;
    }

    if (slow) {
      slow->next = NULL;
      tail->next = slow;
    }

    return dmy.next;
}

/*
   递归版本
*/

struct ListNode* swapPairs(struct ListNode* head)
{
  struct ListNode *l1, *l2;

  if (!head || head->next == NULL) {
    return head;
  }

  l1 = head;
  l2 = head->next;

  l1->next = swapPairs(l2->next);
  l2->next = l1;

  return l2;
}