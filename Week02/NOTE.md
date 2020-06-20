学习笔记

# 哈希表
实现方式： 空间换时间，拉链法解决冲突
时间复杂度： 查找O(1)，最坏o(n)
应用场景: 

# 二叉树
访问方式：
递归：按照根节点访问的位置，分为中序，前序，后序， 层级遍历, 叶子节点会被访问两次。
迭代：辅助栈依次保存访问节点。

DFS方式自顶向下 访问节点
```c
void Visit(struct Node *n)
{
    /* do something */
    Visit(n->left);
    Visit(n->right);
}
```

自低向上至访问。
```c
void Visit(struct Node *n)
{
    left = Visit(n->left);
    right = Visit(n->right);

    /* do something */
}
```
# 搜索二叉树
# 平衡二叉树
# 堆