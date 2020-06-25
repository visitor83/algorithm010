/*
 * @lc app=leetcode.cn id=111 lang=c
 *
 * [111] 二叉树的最小深度
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

int minDepth(struct TreeNode* root)
{
    int l, r;
    
    /* only use for the scene of root node is null */
    if (!root) {
        return 0;
    }

    if (!root->left && !root->right) {
        return 1;
    }
    if (root->left) {
        l = minDepth(root->left);
    }
    if (root->right) {
        r = minDepth(root->right);
    }
    return fmin(l, r) + 1;
}

// @lc code=end

