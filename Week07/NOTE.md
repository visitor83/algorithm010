学习笔记

## Trie
应用：统计和排序大量字符串， 最大限度减少字符比较，查询效率高于HASH， 字符压缩有见过。   
数据结构中需注意： 
1. 前缀， 节点不保存字符 
2. end 标志是否有字符结束 

## 并查集 
应用 ： 集合, 连通性问题，多叉树实现，通过路径压缩将众多孩子挂再同一个父节点下。
基本操作:
1. Init- 初始化时各个节点指向自己， 每个节点一个集合。
2. Union - 两个节点是否时伙伴，查户口看祖宗十八代根上是不是一家子，不是就拜把子，认祖宗。
3. Find - 找祖宗是不是一家子人， 可以使用路径压缩缩短访问路径长度。 

### 模板
``` c
// 返回x的祖宗是谁
int find (int x) {
    if (x != parent[x]) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}
void setUnion(int a, int b) {
    int rootA = find(a), rootB = find(b);
    if (rootA != rootB) {
        parent[rootA] = rootB;
    }
}
```
## 双端BFS 



## 减枝
- [ ] [37. 解数独](https://leetcode-cn.com/problems/sudoku-solver/)  
思路:  
通过同一行、列，$3X3$格子内相互冲突减枝。$3X3$冲突，先压缩左边在确定范围。
```c
bool Validate(char ** board, char **a, int x, int y, char val, 
    int N)
{
    int i, j;
    // row
    for (i = 0; i < N; i++) {
        if (a[x][i] == val )  {
            return false;
        }
    }
    // col
    for (i = 0; i < N; i++) {
        if (a[i][y] == val )  {
            return false;
        }
    }
    int x0, y0;
    x0 = (x / 3 ) * 3; y0 = (y / 3) *3;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (a[x0 + i][y0+j] == val) {
                return false;
            }
        }
    }
    return true;
}
```

- [X] [51. n皇后](https://leetcode-cn.com/problems/n-queens/)
1. 思路： 回溯，每行尝试列上是否可以放置，可以放0~n 数组， 否则-1无效。
2. 截止条件： 行达到 n 则有效解。
3. 回溯条件： 每行上放置判断相同列，或者左撇，右捺是否有冲突，如下：
```c
bool Validate(int n, int *vis, int row, int col) {
    int i, j;
    for (i = 0; i < row; i++) {
        if (vis[i] == col) {
            return false;
        }
    }
    for (i = row - 1, j = col + 1; j < n && i >= 0; i--, j++) {
        if (vis[i] == j) {
            return false;
        }
    }
    for (i = row -1, j = col - 1; j >=0 && i >= 0; i--, j--) {
        if (vis[i] == j) {
            return false;
        }
    }
    return true;
}
```

## 启发式搜索
BFS 模板普通队列替换为优先级队列。