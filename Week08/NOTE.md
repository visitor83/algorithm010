学习笔记


# 位运算

1. n & (n-1)  第一个n为1的BIT位清零  
[190. 颠倒二进制位](https://leetcode-cn.com/problems/reverse-bits/)  
思路：  
负数情况，必须使用移位操作，高位才会正确补符号位。  
[231.2的幂](https://leetcode-cn.com/problems/power-of-two/)  
思路:  
求是否与一个1存在，通过$n*(n-1)$降低时间复杂度

2. x最右边的n位清0,  x & (~0 << n)
3. 奇偶判断, x & 1 == 1, x & 1 == 0
4. 最低位的1,   X & (-X)


# 布隆过滤器

# LRU  缓存器 $O(1)$
[146. LRU缓存机制](https://leetcode-cn.com/problems/lru-cache/)  
思路：  
哈希表查找加速$O(1)$，双向链表实现队列，前驱节点快速移动。

# 排序
[493. 反转对](https://leetcode-cn.com/problems/reverse-pairs/)  
思路：  
归并排序，左右两边都以排序可以去重，合并时统计反转对。



[56. 合并区间](https://leetcode-cn.com/problems/merge-intervals/)  
思路：  
按照起点排序， 注意合并区间比较对象是当前intervals与已求的的区间比较是否合并。

## 冒泡排序 $O(n^2)$
1. 是否原地排序 -- 是
2. 是否稳定  -- 当有相邻两元素大小相等，不做交换 

```c
// 只有交换才可以改变两个元素的前后顺序，稳定性： 当有相邻元素相等，不交换
void BubbleSort(int *a, int numsSize) {
    int i, j;
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < numsSize - i - 1; j++) {
            if (a[j] > a[j+1]) {
                int tmp = a[j]; a[j] = a[j+1]; a[j+1] = tmp;
            }
        }
    }
    return ;
}
```
## 选择排序 $O(n^2)$
前面已排序区间一直保持有序，将后面未排序区间每个元素插入到前面有序数中。  
1. 是否原地排序 - 是
1. 是否稳定？ -- 插入相同元素是，将后出现元素插入在后面 
```c
void InsertSort(int *a, int numsSize) {
    int i, j;
    for ( i = 1; i < numsSize; i++) {
        int value = a[i];
        for (j = i - 1; j >= 0; j--) {
            if (a[j] > value) {
                a[j+1] = a[j]; 
            } else {
                break;
            }
        }
        a[j+1] = value;
    }
}
```

## 归并排序 $nlog(n)$
1. 是否稳定？ -- 是

```C 
void mergeSort(int *nums, int lo, int hi) {
    int mid;
    // 终止条件空间为0
    if (lo >= hi) {
        //return num[lo];
        return ;
    }

    mid = lo + ((hi - lo) >> 1);
    mergeSort(nums, lo, m); mergeSort(nums, m + 1, hi);
    // merge
    new array = [0 .. hi - lo + 1]
    // 左右两边已经排序，相当于两个已排序数组合并操作
    i = lo; j = m + 1;
    while (i <= m  && j <= hi) {
        if (nums[i] <= nums[j]) { array[k++] = nums[i++];}
        else {
            array[k++] = nums[j++];
        }
    }
    // 那个子数组还有剩余
    start = i, end = m;
    if (j <= hi) { start = j; end = hi;}

    // 将剩余数据拷贝到临时数组
    while (start <= end) {
        array[k++] = nums[start++];
    }

    // 数据拷贝回去
    memcpy(&nums[lo], array, sizeof(int) * (hi - lo + 1));
}
```

## 快速排序 $nlog(n)$
1. 是否稳定？