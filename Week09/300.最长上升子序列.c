/*
 * @lc app=leetcode.cn id=300 lang=c
 *
 * [300] 最长上升子序列
 */

// @lc code=start
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int lengthOfLIS(int* nums, int numsSize)
{
    int i, j, end = 0, max;
    //int m[N] = {0};
    int *m;
    int res = 0;

    if (nums == NULL || numsSize == 0) {
      return 0;
    }

    if (numsSize ==  1) {
      return 1;
    }

    m = (int *)malloc(sizeof(int) * numsSize);
    memset(m, 0, sizeof(int) * numsSize);

    m[0]  = 1; 
    for (end = 1; end < numsSize ; end++) {
      max = 0;
      for (j = 0; j  < end; j++) {
          if (nums[end] > nums[j]) {
            max = MAX(m[j], max);
          }
      }
      m[end] = max + 1;
      res = MAX(m[end], res);
  }

  free(m);

  return res;
}
// @lc code=end

