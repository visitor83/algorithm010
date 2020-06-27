/*
 * @lc app=leetcode.cn id=105 lang=c
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int *g_preoder;
int g_prorderSize;

int FindInOrder(int *inorder, int insize, int findVal)
{
    int i;
    for (i = 0; i < insize; i++) {
        if (inorder[i] == findVal) {
            return i;
        }
    }
    return -1;
}
/* 核心思想： 分治*/
struct TreeNode *Helper(int *curPre, int *inorder, int insize, int left, int right)
{
    /* terminator */
    if (left == right) {
        return NULL;
    }

    /* conquer subproblems */
    struct TreeNode *lt, *rt, *curNode;
    int pivot;

    curNode = calloc(1, sizeof(struct TreeNode));
    curNode->val = g_preoder[*curPre];
    (*curPre)++;

    printf("curNode val %d\n", curNode->val);
    pivot = FindInOrder(inorder, insize, curNode->val);
    if (pivot == -1) {
        printf("error \n");
    }

    /* [left pivot] ? */
    lt = Helper(curPre, inorder, insize, left, pivot);
    rt = Helper(curPre, inorder, insize, pivot + 1, right);

    /* process and generate the final result */
    curNode->left = lt;
    curNode->right = rt;

    /* revert the current level state */
    return curNode;
}

struct TreeNode *Helper2(int *curPre, int *inorder, int insize, int left, int right)
{
    /* 因为传入的区间范围为[left, right)截止条件不同 */
    if (left > right) {
        return NULL;
    }

    /* conquer subproblems */
    struct TreeNode *lt, *rt, *curNode;
    int pivot;

    curNode = calloc(1, sizeof(struct TreeNode));
    curNode->val = g_preoder[*curPre];
    (*curPre)++;

    printf("curNode val %d\n", curNode->val);
    pivot = FindInOrder(inorder, insize, curNode->val);
    if (pivot == -1) {
        printf("error \n");
    }

    /* [left pivot] ? */
    lt = Helper2(curPre, inorder, insize, left, pivot - 1);
    rt = Helper2(curPre, inorder, insize, pivot + 1, right);

    /* process and generate the final result */
    curNode->left = lt;
    curNode->right = rt;

    /* revert the current level state */
    return curNode;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
    int curPre = 0;

    g_preoder = preorder;
    g_prorderSize = preorderSize;
    /* 传入的左闭右开 [left, right) */
    return Helper(&curPre, inorder, inorderSize, 0, inorderSize );
}

// @lc code=end

