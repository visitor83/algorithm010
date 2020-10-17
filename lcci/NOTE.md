链表: 
- [X] 环路检测, slow, fast起点都是head, 先判断是否有环，再同步slow, fast每次步数，寻找相交点。

递归：
- [X] 04.12 求和路径： 再递归路径上做前缀和+hashap。
- [X] 08.02 迷失的机器人： 递归记忆化。 
  递推公式：  
  ```C
     res = (x == 0 && y == 0 ) || myfunc(grid, ROW, COL, x, y -1, returnSize, found, ans) ||
        myfunc(grid, ROW, COL, x-1, y , returnSize, found,ans);
  ```