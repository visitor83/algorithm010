/*
 * @lc app=leetcode.cn id=589 lang=c
 *
 * [589] N叉树的前序遍历
 */

// @lc code=start
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */
#define MAXN  1024
typedef struct tagStack {
  struct Node *n;
  struct tagStack *next;
} Stack;

typedef struct tagList {
  int val;
  struct tagList * next;
} List;

void Push(Stack *head, struct Node *n)
{
  Stack *stk = calloc(1, sizeof(Stack));
  stk->n = n;
  stk->next = head->next;
  head->next = stk;
}

Stack * Pop(Stack *head)
{
  Stack *stk;
  stk = head->next;
  if (stk == NULL) {
    return NULL;
  }
  head->next = stk->next;
  return stk;
}

bool IsEmpty(Stack *head)
{
  return head->next == NULL ? true : false;
}

List *NewList(int val)
{
  List *tmp = calloc(1, sizeof(List));
  tmp->val = val;
  return tmp;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorder(struct Node* root, int* returnSize) 
{
  Stack *head, *cur;
  struct Node *node;
  List dmy, *tail, *nodel;
  int *ans;
  int ansCnt;

  head = calloc(1, sizeof(Stack));
  tail = &dmy;

  ansCnt = 0;
  if (!root) {
    *returnSize = 0;
    ans = calloc(1, sizeof(int));
    return ans;
  }

  Push(head, root);
  while (!IsEmpty(head)) {
    cur = Pop(head);
    node = cur->n;
    //ans[ansCnt++] = node->val;
    ansCnt++;
    nodel = NewList(node->val);
    tail->next = nodel;
    tail = nodel;

    for (int i = node->numChildren - 1; i != -1; i--) {
      Push(head, node->children[i]);
    }
  }

  List *p = dmy.next;
  int i = 0;
  ans = calloc(ansCnt, sizeof(int) );
  while (p != NULL) {
    ans[i++] = p->val;
    p = p->next;
  }
  *returnSize = ansCnt;
  return ans;
}
// @lc code=end

