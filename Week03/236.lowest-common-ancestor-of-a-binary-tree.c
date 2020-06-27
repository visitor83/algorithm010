/*
 * @lc app=leetcode.cn id=236 lang=c
 *
 * [236] 二叉树的最近公共祖先
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
/*
TestCase :
 1: p, q : on the each side of root
 4: p is left leafnode, q : root
 5: p is left noleafnode, q is right no leafnode
 6: p, q on the left subtree
*/
 struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) 
{
    if (!root) {
        return root;
    }
    
    /* terminator */
    if (root == p || root == q) {
        return root;
    }
    
    /* current level logic */
    struct TreeNode *left, *right;

    /* drill down */    
    left = lowestCommonAncestor(root->left, p, q);
    right = lowestCommonAncestor(root->right, p, q);

    /* p, q on the each side of current node*/
    if (left && right) {
        return root;
    }

    if (!left) {
        return right;
    }
    if (!right) {
        return left;
    }
    /* NOTE: is root or NULL ??? */
    return root;
    
    /* revert curent levle state*/
    
}
// @lc code=end

