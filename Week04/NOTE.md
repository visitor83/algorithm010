学习笔记

# DFS： 
> 基本思想: 一直向一个方向搜索，直到碰到无法进行下一步，返回上一层寻找其他搜索方向。  
时间复杂度: 每个节点访问且只访问一次，使用递归的编程方式，但对于节点的访问顺序没有要求
## 模板  
> 递归版本
``` C
void dfs(void) 
{
  if node in visited:
    return;
    visited.add(node)
    // process node in node.children:
    If not next_node in visited:
    dfs(next node, visited)
}
```

# BFS 
> 应用场景： 寻着两个节点之间最小路径（无向图计算边树)  
时间复杂度:优与DFS但由于使用队列作为辅助数据结构，空间复杂度要高于DFS。  
技巧：  
1. 双端BFS : 同时从起点和终点起步，当相遇时就是解。
2. 优先级队列： 队列元素按照指定某种优先级排列，迪克斯拉杰算法

### 模板
``` python
BFS(graph, start, end)
  	queue = []
    //queue add the start point
    visited.add(start)
    while queue is not empty:
        node = queue.pop()
        visited.add(node)
        //process node 
        nodes = generate related nodes(node)
        queue.push(nodes)
```
### 例题
- [X] [529. 扫雷游戏](https://leetcode-cn.com/problems/minesweeper/)  
核心思想:
1. 起始条件：点击的点和邻居8个点都不是雷。才可以继续向外扩一层。
2. 搜索停止条件： 节点邻居有'M', 不能靠近, 截止的层是**数字节点**。存在 'E'节点没有被访问，因为'E'的邻接都是数字节点和'M'雷。

# 贪心算法
## 基本思想
每次选择局部最优的选择，结果就是全局的最优。贪心策略有时很难证明。选择几个典型的贪心场景学习下。  
> 贪心策略： 在限制值贡献相同的情况下，选择对期望值贡献最大的值。

- [X] [55 跳跃游戏](https://leetcode-cn.com/problems/jump-game/)  
核心思想：  
每步选择:从历史最远和当前位置可跳的最远的位置, 选择最远位置更新搜索的边界。  
- [X] [860. 柠檬水找零](https://leetcode-cn.com/problems/lemonade-change/)  
核心思想:  
每步选择:最大的钱数找零，（因为找零的钱都是倍数关系，所以可以使用此贪心方式)  
- [X] [122. 买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/)  
核心思想:
每步选择： 买进：包括当前位置开始右侧连续点中价格最低点， 卖出: 选择价格最低点(low)右侧价值最大的点则收益最大。  
![avatar](https://pic.leetcode-cn.com/d447f96d20d1cfded20a5d08993b3658ed08e295ecc9aea300ad5e3f4466e0fe-file_1555699515174)

- [ ] 区间覆盖 
# 二分查找

## 基本思想
[二分简介](https://leetcode.com/articles/introduction-to-binary-search/)
时间复杂度: 有序或者部分有序， O(logN)

## 应用场景
1. 求最大化最小值， 最小化最大值。
2. 判断性问题搜索解。
## 模板
###  **搜索区间 [left, right]**
``` java
public int binarySearch(int[] nums, int target) {
    int left = 0, right = nums.length - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (target > nums[mid]) left = mid + 1;
        else if (target < nums[mid]) right = mid - 1;
        else if (target == nums[mid]) return mid;
    }
    return -1;
}
> Template 2
Find first occurrence of the target

public int binarySearch(int[] nums, int target) {
    int left = 0, right = nums.length - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (target > nums[mid]) left = mid + 1;
        else if (target < nums[mid]) right = mid - 1;
        else if (target == nums[mid]) right = mid - 1;
    }
    if (left >= nums.length || nums[left] != target) return -1;
    return left;                                                
}
> Template 3
Find last occurrence of the target
public int binarySearch(int[] nums, int target) {
    int left = 0, right = nums.length - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (target > nums[mid]) left = mid + 1;
        else if (target < nums[mid]) right = mid - 1;
        else if (target == nums[mid]) left = mid + 1;
    }
    if (right < 0 || nums[right] != target) return -1;
    return right;                                                
}
```
## 搜索空间[left, right)
---
# 练习题总结
- [X] [74. 搜索二维矩阵](https://leetcode-cn.com/problems/search-a-2d-matrix/)  
核心思想:  
1. 如果选择左上角，和右下角对角线每次比较后排除某一行或者列；继续使用举例子方式提取规律然后再验证的方法，选择右上角到左下角对角线，每次比较后可以排除一行或者一列。  
2. 搜索空间: row < Row, col < Column
3. 判定条件:  
   - 右上角pivot[0][Column-1] > aim, 则数据在 Column-1列, pivot的下面, 排除一行
   - pivot[0][Column-1] < aim, 则数据在 Column-1列左边, pivot的左侧, 排除一列

- [X] [153. 寻找旋转排序数组中的最小值](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/)  
核心思想:  
求最小值，求数组的下限， 相等情况下right缩小范围， 终止条件 left < right 

- [X] [33. 搜索旋转排序数组](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)  
核心思想:  
求搜索目标值，在有序的部分判断目标值是否在区间取值范围内进行二分查找。  
- [X] [69. x 的平方根](https://leetcode-cn.com/problems/sqrtx/)  
核心思想：  
1. 二分判定性问题: 
2. 判断条件时 mval*mval <= x
3. 搜索目标： mval 满足条件2的下边界值
4. 截止条件： 搜索空间[1, x]， 截止条件: low <= high

- [X] [面试题 08.03. 魔术索引](https://leetcode-cn.com/problems/magic-index-lcci/)  
核心思想：  
1. 截止条件 lo > hi返回没找到-1
2. 搜素空间[0, numsSize - 1]
3. 二分判断条件nums[m] 是否等于m索引。
4. nums有重复值则需要**根据当前nums[i]与i的关系确定下一步搜素范围**

- [X] [658. 找到 K 个最接近的元素](https://leetcode-cn.com/problems/find-k-closest-elements) 
思想：  
1. 左右两个边界处理
2. 二分求取目标值，双指针搜索[x - arr[m], x + arr[m]]

- [X] [162. 寻找峰值](https://leetcode-cn.com/problems/find-peak-element/)  
1. 二分比较条件：
   - nums[i] < nums[i+1], [m + 1, hi]
   - nums[i] >= nums[i+1], [lo   , m] ??
2. 截止条件 ==lo == hi==， 每次比较有2个元素。


# BFS使用队列数据结构

## 链式
接口:  
QCreate:  
QEnq:  
QDeq:  
QIsEmpty:  
QGetSize:

```C
typedef struct tagNode {
    char *arr;
    struct tagNode *next;
} Node;

typedef struct tagQueue {
    Node *front, *rear;
    int qsize;
} Queue;

Node *g_head;

Queue *QCreate()
{
    Queue *q = calloc(1, sizeof(Queue));
    q->front = q->rear = calloc(1, sizeof(Node));
    q->qsize = 0;
    return q;
}

void QEnq(Queue *q, char *s)
{
    Node *n = calloc(1, sizeof(Node));

    n->arr = s;
    q->rear->next = n;
    q->rear = n;
    ++(q->qsize);
}

Node *QDeq(Queue *q)
{
    Node *n = q->front->next;

    q->front->next = n->next;
    if (q->rear == n) {
        q->rear = q->front;
    }
    --q->qsize;
    return n;
}

bool QIsEmpty(Queue *q)
{
    return (q->qsize == 0) ? true : false;
}
```