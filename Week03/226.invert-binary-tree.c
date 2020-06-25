/*
 * @lc app=leetcode.cn id=226 lang=c
 *
 * [226] 翻转二叉树
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

struct TreeNode* invertTree(struct TreeNode* root)
{
    struct  TreeNode *l, *r;

    if (!root) {
        return root;
    }

    l = invertTree(root->left);
    r = invertTree(root->right);

    root->left = r;
    root->right = l;
    return root;
}

// @lc code=end

