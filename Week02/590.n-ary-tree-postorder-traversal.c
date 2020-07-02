/*
 * @lc app=leetcode.cn id=590 lang=c
 *
 * [590] N叉树的后序遍历
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

typedef struct tagList {
  int val;
  struct tagList * next;
} List;

int *g_ans;
int g_ansCnt;
List *g_ptail;

List *NewList(int val)
{
  List *tmp = calloc(1, sizeof(List));
  tmp->val = val;
  return tmp;
}

void postorder2(struct Node *node)
{
  List *el;
  int i;
  if (!node) {
    return ;
  }
  for (i = 0; i < node->numChildren; i++) {
    postorder2(node->children[i]);
  }

  el = NewList(node->val);
  g_ptail->next = el;
  g_ptail = el;
  g_ansCnt++;
  return ;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* postorder(struct Node* root, int* returnSize)
{
  int i;
  List dmy;

  g_ansCnt = 0;
  g_ptail = &dmy;

  if (!root) {
    *returnSize = 0;
    g_ans = calloc(1, sizeof(int));
    return g_ans;
  }

  postorder2(root);

  i = 0;
  g_ans = calloc(g_ansCnt, sizeof(int));
  List *p = dmy.next;
  while (p != NULL) {
    g_ans[i++] = p->val;
    p = p->next;
  }
  *returnSize = g_ansCnt;
  return g_ans;
}

/*
  迭代版本
*/
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

void InsertHead(List *head, int val)
{
  List *newone = NewList(val);
 
  newone->next = head->next;
  head->next = newone;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* postorder(struct Node* root, int* returnSize)
{
  Stack *head, *cur;
  struct Node *node;
  List dmy;
  int *ans;
  int ansCnt;

  head = calloc(1, sizeof(Stack));
  dmy.next = NULL;

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
    InsertHead(&dmy, node->val);
    ansCnt++;
    for (int i = 0; i < node->numChildren; i++) {
      Push(head, node->children[i]);
    }
  }

  List *p = dmy.next;
  int i = 0;
  ans = calloc(ansCnt, sizeof(int) );
  while (p != NULL ) {
    ans[i++] = p->val;
    printf("%d ", p->val);
    p = p->next;
  }
  *returnSize = ansCnt;
  return ans;
}
// @lc code=end

