/*
 * @lc app=leetcode.cn id=213 lang=c
 *
 * [213] 打家劫舍 II
 */

// @lc code=start

int GetRob(int *nums, int numsSize, int s, int e)
{
    int i;
    int *dp;

    dp = calloc(numsSize + 2, sizeof(int));

    for(i = s ; i < e; i++) {
        dp[i+2] = fmax(dp[i] + nums[i] , dp[i+1]);
    }
    return dp[e + 1];
}

int rob(int* nums, int numsSize)
{
    if (numsSize == 1) {
        return nums[0];
    }
    return fmax(GetRob(nums, numsSize, 0, numsSize - 1),
                 GetRob(nums, numsSize, 1, numsSize)) ;
 }

// @lc code=end

