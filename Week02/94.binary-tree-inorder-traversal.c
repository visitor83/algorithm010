/*
 * @lc app=leetcode.cn id=94 lang=c
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct tagNode {
  struct TreeNode *t;
  struct tagNode *next;
} Node;

void Push(Node *head, struct TreeNode *t)
{
  Node *n = calloc(1, sizeof(Node));
  n->t = t;
  n->next = head->next;
  head->next = n;
}

Node * Pop(Node *head)
{
  if (head->next == NULL) {
    printf("Empty\n");
    return NULL;
  }
  Node *n = head->next;
  head->next = n->next;
  return n;
}

bool IsEmpty(Node *head)
{
  return head->next == NULL ? true : false;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
  Node *head, *node;
  struct TreeNode * cur;
  int *ans;
  int ansCnt = 0;

  head = calloc(1, sizeof(Node));
  ans = calloc(1024, sizeof(int));
  cur = root;
  while (cur != NULL  || !IsEmpty(head)) {
    while (cur != NULL) {
      Push(head, cur);
      cur = cur->left;
    }
    node = Pop(head);
    ans[ansCnt++] = node->t->val;
    cur = node->t->right;
  }
  *returnSize = ansCnt;
  return ans;
}

// @lc code=end

