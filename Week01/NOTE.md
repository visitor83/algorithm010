学习笔记

# 双指针

按照某种规则更新快慢指针，$O(n)$ 解决区间搜索，

## 同向快慢指针

[283. 移动零](https://leetcode-cn.com/problems/move-zeroes/)  
思想:
- 定义慢指针： 非0元素的子数组末尾 + 1; 快指针 当前元素
- 子问题： 当快指针 非0时 与慢指针交换，[0, slow -1, slow],其中 slow位置有可能时0/非0。  
  0：与fast 正常交换
  非0: 不可能， [slow, fast]  之间只可能是0
时间复杂度$O(n)$

## 多个快慢指针

[75. 颜色分类](https://leetcode-cn.com/problems/sort-colors/)  
思想:
- 子问题： [0, i] 蓝色区域 

## 两侧夹逼

[15. 三数之和](https://leetcode-cn.com/problems/3sum/)  
思想： 
- 先排序，暴力解$O(n^3)$
- 优化方向： 去除暴力解的3重循环， 哈希？？
- 目标：固定前两循环a, b, 寻找唯一的 c 满足 $a + b + c = 0$， 第二重循环b 枚举$b'$ , $b' >  b$(数组排序过), 那么第三层循环 c枚举$c'$，必然有$c' <c$
- 子问题: 固定a, b 从小到大枚举， C从大到小枚举  
时间复杂度: $O(n^2)$

# 链表

[25. K 个一组翻转链表](https://leetcode-cn.com/problems/reverse-nodes-in-k-group/)  
思想:
- 递归
- 子问题：求本层k个一组反序， 更改本递归层头和尾指针。

[142. 环形链表 II](https://leetcode-cn.com/problems/linked-list-cycle-ii/)  
思想:  
- slow, fast同时起步（如果不在同一起点，会死循环，两个无法在圈里相遇)， 快两步走，慢一步走
- 截止条件: slow == fast, 或者fast , fast->next == NULL
- slow, fast 以一步同时起跑，但起点不一致，相遇则是求解节点。
  
# 队列

## 双端循环队列

[641. 设计循环双端队列](https://leetcode-cn.com/problems/design-circular-deque/)  
思想：  
- 队列容量cap要比要求的容量k, 预留1个空位，判断队列是否满 
  ```c
    bool myCircularDequeIsFull(MyCircularDeque* obj) {  
        return ((obj->rear + 1) % obj->cap) == obj->front ? true : false;
    }
  ```
- insertFront时考虑回绕
  ```c
    obj->front = (obj->front - 1 + obj->cap) % obj->cap;
  ```
-  初始配置 队列起始都是0， 所以尾部入队列时需**先入队列， 后移动 obj->rear索引+1。

## 优先级队列


# 单调栈
寻找临近元素的下一个最大值，或者最小值，保持栈内元素单调递增或递减。


# 滑动窗口

[3. 无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/)  
[239. 滑动窗口最大值](https://leetcode-cn.com/problems/sliding-window-maximum/)


# 模板


## 数组循环队列

```C
struct TreeNode * g_queue[MAX_NODE];

int g_front, g_rear, g_qsize;
void QInit()
{
    g_front = g_rear = 0;
    g_qsize = 0;
}

void QEnq(struct TreeNode *tn)
{
    g_queue[g_rear] = tn;
    g_rear = (g_rear + 1) % MAX_NODE;
    g_qsize++;
}

struct TreeNode * QDeq()
{
    struct TreeNode * tn;
    tn = g_queue[g_front % MAX_NODE];
    g_front = (g_front + 1) % MAX_NODE;
    g_qsize--;
    return tn;
}

bool QIsEmpty()
{
    return g_qsize == 0 ? true : false;
}
```