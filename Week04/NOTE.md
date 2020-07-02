学习笔记


# 二分查找

## 基本思想
1. 有序或者部分有序， O(logN)时间复杂度

## 应用场景
1. 求最大化最小值， 最小化最大值。
2. 判断性问题搜索解。
## 模板


# 练习题总结
[153. 寻找旋转排序数组中的最小值](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/)  
核心思想:  
求最小值，求数组的下限， 相等情况下right缩小范围， 终止条件 left < right 

[33. 搜索旋转排序数组](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)  
核心思想:  
求搜索目标值，在有序的部分判断目标值是否在区间取值范围内进行二分查找。  