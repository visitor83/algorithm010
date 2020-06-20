/*
 * @lc app=leetcode.cn id=144 lang=c
 *
 * [144] 二叉树的前序遍历
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

void Push(Node *head, struct TreeNode *tn)
{
    Node *n;
    n = calloc(1, sizeof(Node));
    n->t = tn;
    n->next = head->next;
    head->next = n;
}
Node *Pop(Node *head)
{
    Node *n;
    n = head->next;
    head->next = n->next;
    return n;
}

bool IsEmpty(Node *head)
{
    return head->next == NULL ? true :false;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    Node *head, *node;
    struct TreeNode *cur;
    int *ans;
    int ansCnt;

    head = calloc(1, sizeof(Node));

    ans = calloc(1024, sizeof(int));
    ansCnt = 0;
    cur = root;
    while (cur != NULL || !IsEmpty(head)) {
        while (cur != NULL) {
            ans[ansCnt++] = cur->val;
            Push(head, cur);
            cur = cur->left;
        }
        node = Pop(head);
        cur = node->t->right;
    }
    *returnSize = ansCnt;
    return ans;
}


// @lc code=end

