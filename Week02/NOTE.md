学习笔记


# 哈希： 
应用: 哈希函数散列，对相同哈希值的元素使用拉链法或者开放地址法解决冲突问题。  
实现方式： 空间换时间，拉链法解决冲突  
时间复杂度： 查找O(1)，最坏o(n)  
应用场景: 
1. 元素去重
2. 预处理数据，在暴力法中去除一层循环，加速查找。 
3. 统计字频。

# 二叉树
## 访问方式：
- 递归：按照根节点访问的位置，分为中序，前序，后序， 层级遍历, 叶子节点会被访问 三次， 只是将打印节点的时机放置在不同访问时间点。
```c
void Inorder(struct TreeNode * n)
{
    if (!n) {
        return n;
    }
    Inorder(n->left);
    printf("%d", n->val);
    Inorder(n->right);
}
```
- 迭代：辅助栈依次保存访问节点，例如下面迭代版本的中序遍历。
初始条件：头节点Head作为当前节点。
  1. 访问节点的最左边孩子，并将访问路径上的节点入栈。
  2. 最左边孩子leftMostChild出栈，并保存结果。
  3. leftMostChild的右孩子入栈。从1开始重复问题处理。
```c
int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
  Node *head, *node;
  struct TreeNode * cur;
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
```

DFS方式自顶向下 访问节点
``` c
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
性质： 
1. 所有的左孩子的值  <= root node's val <= 所有右孩子的值
2. 中序遍历搜索二叉树，序列递增。
# 平衡二叉树
# 堆
**一般使用数组实现，大根堆，小根堆**

 实现方法:   
数组实现： left child = parent * 2, right child = parent * 2 + 1  
优先队列： <value, priority> 为一个Pair，每次入队列时根据优先级调整队列，中可以使用Sort每次都拍一次序  O(nlogn)； 使用链表则需要每次找到插入点O(n)，然后插入。
应用场景
1. Dijstra算法借助优先级队列维持，起点到每个节点的最短路径(Short Path)，相临节点不同优先级可以重复插入，队列pollFirst时如果队列元素已经访问过(seen）则丢弃出队节点。
    * 优先级队列
    * 是否已经遍历过seen标示数组
    * 各节点的最短路径的Parent 是谁
    * Distance从起点到当前节点的最短路径。
2. 数据动态变化场景下，求Topk 个数据。
3. 任务优先级调度问题。

# 图
- 无向图
- 有向图
- 加权图
## 图的表示方式
1. 邻接矩阵， 链式前向星方式
2. 链表，过于复杂。

##  图搜索：
对比树的访问，图因为有环存在所以**必须使用标记数组 Visitd记录访问过的点**。

  时间复杂度 : 

  空间复杂度
1. DFS (深度优先搜索)， 不撞南墙不回头，
    * 拓扑排序
    * 连通性问题
    * 二分图
    * 环路检测
2. BFS (广度优先搜索)， 如一颗石子激起水中的涟漪, 层层传播，每次从队列里取一个元素，每次将队列的所有数据取完。
    * 无相图的最短路径问题，因为无向图统计的是边长。
    *  DFS性能不足情况下，使用BFS同时将多个起点塞入队列，同时齐步走遍历速度要快于DFS。
3. **双端BFS**


