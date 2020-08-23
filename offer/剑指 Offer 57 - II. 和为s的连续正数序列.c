/*
输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

 

示例 1：

输入：target = 9
输出：[[2,3,4],[4,5]]
示例 2：

输入：target = 15
输出：[[1,2,3,4,5],[4,5,6],[7,8]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 void CopyRes(int *a, int st, int ed) {
     int i, j;
     for (i = st, j = 0; i < ed; i++) {
         a[j++] = i;
     }
 }
int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
  int i, j;
  int sum = 0;
  int **a, ansCnt = 0;

  a = calloc(target << 1, sizeof(int*));
  *returnColumnSizes = calloc(target << 1, sizeof(int));
  *returnSize = 0;
  sum  = 0;
  for (i = 1, j = 1; i < target  && j < target; ) {
    if (sum < target) {
      sum = sum + j;
      ++j;
    } else if (sum == target) {
      //printf("[%d, %d]\n", i, j-1);
      a[ansCnt] = calloc(j - i + 1, sizeof(int));
      CopyRes(a[ansCnt], i, j); (*returnColumnSizes)[ansCnt] = j - i;
      ansCnt++;
      sum = sum - i;
      i++;
    } else if (sum > target) {
      sum = sum - i;
      i++; 
    }
  }
  //printf(" ansCnt %d\n", ansCnt);
  *returnSize = ansCnt;
  //printf("%d %d\n", (*returnColumnSizes)[0], (*returnColumnSizes)[1]);
  /*
  for (i = 0; i < ansCnt; i++) {
      for (j = 0; j < (*returnColumnSizes)[i]; j++) {
          printf("%d, ", a[i][j]);
      }
      printf("\n");
  }
  */
  return a;
}