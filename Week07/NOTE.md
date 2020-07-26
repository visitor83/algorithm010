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


## 启发式搜索
BFS 模板普通队列替换为优先级队列。