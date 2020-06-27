学习笔记

# 递归 
 1. 终止条件 terminator 
 2. 当前层处理逻辑 Process current level logic
 3. 下一层处理 drill down，有些状态参数改变了但没有破坏当前层的梦境
 4. 如果需要清理当前层的状态， Reverse the current level status,  如果使用的是当前函数栈保存当前层状态不需要清理，如果有全局变量等需要恢复。
## 递归思维训练
 1. 人脑喜欢暴力求解， 不要人肉递归（初阶画递归树，高阶尽量寻找**重复子问题**
 2. 寻找最近重复子问题，计算机擅长重复子问题。 
 3. 数学归纳法， 先尝试最基本的条件下是否成立，再看N+1是否成立。

总结： 写递归程序，先自顶向下，先写好terminator终止条件防止程序进入死循环；发现重复子问题；处理好当前层业务逻辑，并考虑必要的**剪枝条件**(最优化减枝， 可行性减枝)。
# 分治 (divide and conquer)

### 核心思想： 
其实也是递归，替换递归第4步为合并结果。寻找重复子问题，终止条件是再也没有重复子问题需要解决。
### 模版
``` C
void Divide_and_Conquer(problem, param1, param2,...)
{
    // 递归终止条件
    If (problem is None) {
    PrintResult();
    return ;
    // 准备数据
    Data = PrepareData(problem)
    subProblem  = SplitPoblem(problem, Data)

    #conquer subproblem
    subResult1 = Divide_and_Conquer(subProblem[0], p1, ...);
    subResult2 = Divide_and_Conquer(subProblem[1], p1, ...);

    // 处理结果
    Result = ProcessResult(subResult1, subResult2);
    // 清理当前层
}
```
### 快速排序
核心思想  
1. 使用第一个元素或者最后一个元素pivot元素分割数组，使得[0, pivot-1]  pivot  [pivot + 1, lenght -1]
2. [0, pivot-1]数据都小于pivot， [pivot+1, length-1]都大于pivot元素。
3. 插入pivot 到中间位置。
从1开始重新左右两边分别执行。

### 归并排序
1. 分割nums数组，[0,mid], [mid+1, length-1]
2. lo == hi 就只剩一个宝宝了，
3. 递归开始回来了，合并数据，申请临时合并空间保存数据。
4. 把临时合并后数据返回去。


# 回溯 (Backtracing)
### 核心思想： 
其实是一种暴力搜索解空间的方法，如果不是可行解（或者至少不是最后一个解），回溯法会在前一步舍弃候选解。
### 常见回溯问题
1. 组合
2. 排列
3. 分割
4. 其他形式，只是修改了进入回溯的条件。
### 回溯终止条件总结
树回溯： 寻找terminator条件，链表有两种返回截止条件    
1. left == NULL && right == NULL:  访问到子叶子就返回
2. root == NULL 返回即访问到空节点返回  

区间回溯：
[lo, hi]**闭区间**， 截止条件为 lo > hi，其中lo == hi 是有效区间。
[lo, hi)左闭右开，截止条件 lo == hi, 因为hi 已经是区间边界了是无效值。

例题 [105. 从前序与中序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) 

# 练习题易总结
[169 多数元素](https://leetcode-cn.com/problems/majority-element/)  
核心思想  
1. 分治:   
      截止: left == right 此时只有一个元素。 
      分割：[left, m], [m+1, right] 都是闭区间
      合并: 将左右两个分割区间的返回的自区间的最大数，在合并区间[left, right]内统计最大元素个数。
2. 摩尔投票法：  
 
[78 子集](https://leetcode-cn.com/problems/subsets/)  
[77 组合](https://leetcode-cn.com/problems/combinations/)  
核心思想  
回溯：进入下一层时，传递**i+1**做为start起点，**保证组合问题没有重复组合**，控制好组合的深度就可以了。
``` C
    for (int i = start; i < numsSize; i++) {
        stk[dep++] = nums[i];
        /* drill down*/
        Helper(nums, numsSize, range, i + 1,  stk, dep);
        /* reverse current state */
        stk[--dep] = 0;
    }
```
[51 N皇后](https://leetcode-cn.com/problems/n-queens/)  
核心思想  
回溯:进入下一级回溯函数的条件是不受到其他皇后攻击（正反对角线，不在同一行和列), 截止条件：全部皇后都有位置可占。

[226 翻转二叉树](https://leetcode-cn.com/problems/invert-binary-tree/)  
核心思想  
分治，先拆分子问题（左右子树互换)， 后合并左右子树 

[98 验证二叉搜索树](https://leetcode-cn.com/problems/validate-binary-search-tree/)  
核心思想
1. 打擂台， 排序的思想， 使用二叉搜索树中序升序性质
2. 二分思想，自顶向下: left child  <= parent < right child, 使用二分思想，parent值作为左子树的upper bound, 右子树的lower bound，逐步缩小区间范围，自顶向下验证。
3. 自底向上  

[111 二叉树最小深度](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/)  
核心思想  
分治： 分别求左右子树的最小深度, 递归返回时高度+1, 合并结果时比较最小高度返回。**递归终止条件必须为子节点，这个不同于最大深度题**

[50 Pow](https://leetcode-cn.com/problems/powx-n/)  
核心思想
分治：分O(logN)， 合并时处理奇偶情况，注意题目有阶乘为-n情况，以及边界值2^0 = 1情况。

## 编程技巧总结
- 对角线坐标，正反对角线。
- 输入输出三围指针的方法
