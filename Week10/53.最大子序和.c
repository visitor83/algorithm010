/*
 * @lc app=leetcode.cn id=53 lang=c
 * [53] 最大子序和
 */

// @lc code=start

// 子数组的最大累加合问题 P 367
int maxSubArray(int* nums, int numsSize){
    int j,  sum, ans;

// 如果是 负数？？, 子数组和下降
    ans = INT_MIN;
    for(j = 0, sum = 0; j < numsSize; j++) {
        sum += nums[j];
        // 每次sum都求最大值, 小于 0 的SUM已经计算过最大值
        ans = fmax(ans, sum);
        if (sum < 0) {
            sum = 0;
        }    
    }
    return ans;
}

// @lc code=end

