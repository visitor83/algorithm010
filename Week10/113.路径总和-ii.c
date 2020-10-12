/*
 * @lc app=leetcode.cn id=113 lang=c
 *
 * [113] 路径总和 II
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


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 typedef struct tagNode{
     int *arr;
     int alen;
     struct tagNode *next;
 } Node;
 Node g_head, *g_ptail;
 void SaveRes (int *stk, int d, int *returnSize) {
    Node *n;
    n = calloc(1, sizeof(Node));
    n->arr = calloc(d, sizeof(int));
    n->alen = d;
     for (int i = 0; i < d; i++) {
        // printf("%d,", stk[i]);
         n->arr[i] = stk[i];
     }
     g_ptail->next = n;
     g_ptail = n;
     (*returnSize) ++;
 }
 void dfs(struct TreeNode *cur, int sum, int pathSum, int *stk, int d, int *returnSize) {
     // terminator
     /*
     if (cur && !cur->left && !cur->right) {
         if (pathSum + cur->val == sum) {
            stk[d++] = cur->val;
            SaveRes(stk, d);
            (*returnSize)++;
            stk[--d] = 0;
         }
         return ;
     }
     */
     if (!cur) {
         return ;
     }
     stk[d++] = cur->val;
     if (!cur->left && !cur->right && pathSum + cur->val == sum) {
         SaveRes(stk, d, returnSize);
         stk[--d] = 0;
         return ;
     }
     dfs(cur->left, sum, pathSum + cur->val, stk, d, returnSize);
     stk[--d] = 0;

     stk[d++] = cur->val;
     if (!cur->left && !cur->right && pathSum + cur->val == sum) {
         SaveRes(stk, d, returnSize);
         stk[--d] = 0;
         return ;
     }
     dfs(cur->right, sum, pathSum + cur->val, stk, d, returnSize);
     stk[--d] = 0;
 }
 #define N 1024
int** pathSum(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes){
    int **ans;
    int *stk;
    int i;
    stk = calloc(N, sizeof(int));

    *returnSize = 0;
    g_head.next = NULL;
    g_ptail = &g_head;
    dfs(root, sum, 0, stk, 0, returnSize);
    //printf(" returnSize %d\n", *returnSize);

    i = 0;
    ans = calloc(*returnSize, sizeof(int*));
    *returnColumnSizes = calloc(*returnSize, sizeof(int));
    Node *it = g_head.next;
    while (it) {
        ans[i] = it->arr;
        (*returnColumnSizes)[i] = it->alen;
        i++;
        it = it->next;
    }
    return ans;
}

// @lc code=end

