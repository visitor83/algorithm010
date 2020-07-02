学习笔记


# 二分查找

## 基本思想
[二分简介](https://leetcode.com/articles/introduction-to-binary-search/)
1. 有序或者部分有序， O(logN)时间复杂度

## 应用场景
1. 求最大化最小值， 最小化最大值。
2. 判断性问题搜索解。
## 模板
### 搜索区间 [left, right]
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

# 练习题总结
[153. 寻找旋转排序数组中的最小值](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/)  
核心思想:  
求最小值，求数组的下限， 相等情况下right缩小范围， 终止条件 left < right 

[33. 搜索旋转排序数组](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)  
核心思想:  
求搜索目标值，在有序的部分判断目标值是否在区间取值范围内进行二分查找。  