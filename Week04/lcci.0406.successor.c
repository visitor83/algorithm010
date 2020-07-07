/*
设计一个算法，找出二叉搜索树中指定节点的“下一个”节点（也即中序后继）。

如果指定节点没有对应的“下一个”节点，则返回null。

示例 1:

输入: root = [2,1,3], p = 1

  2
 / \
1   3

输出: 2
示例 2:

输入: root = [5,3,6,2,4,null,null,1], p = 6

      5
     / \
    3   6
   / \
  2   4
 /   
1

输出: null

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/successor-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/*
如果中序遍历右子树，那它就会是接下来第一个被访问的节点，也就是说，它应该是右子树最左边的节点
1. 如果n没有右孩子？？ n 的子树都已访问过了， 回到n 的parent
    -  n 在parent 左边 , 返回parent
    -  n 在parent 右边 , 则表示已遍历parent的子树。我们需要从parent往上访问，直至找到还未完全遍历过的节点x。
    怎么才能知道还未完全遍历节点x呢？之前从左节点访问至其父节点时，就已碰到了这种情况。左节点已完全遍历，但其父节点尚未完全遍历。
*/

struct TreeNode* inorderSuccessor(struct TreeNode* root, struct TreeNode* p)
{
    struct TreeNode * node, *parent;
    if (!root || !p) {
        return NULL;
    }

    if (p->right !=  NULL) {
        // find the leftmost
        node = p->right; 
        while (node && node->left != NULL) {
            node = node->left;
        }
        return  node;
    }
    // the left's parent
    node = root;
    parent = NULL;
    while (node != p) {
        if (node->val < p->val) {
            node = node->right;
        } else {
            parent = node;
            node = node->left;
        }
    }

    return parent;
}