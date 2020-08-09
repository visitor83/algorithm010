/*
 * @lc app=leetcode.cn id=746 lang=c
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
int minCostClimbingStairs(int* cost, int costSize){
    int *dp, i;
    if (!cost || costSize <= 0) {
        return 0;
    }

    // dp[i] : 当前i 的最小体力花费
//dp[3] = dp[2] + dp[1]
//dp[2] = dp[0] + dp[1]
    dp = calloc(costSize + 10, sizeof(int));
    dp[0] = cost[0]; 
    dp[1] = cost[1]; 
    for ( i = 2; i < costSize; i++) {
        dp[i] = fmin(dp[i-1], dp[i-2]) + cost[i];
        //printf(" %d: %d, ", i, dp[i]);
    }
    return fmin(dp[i-1], dp[i-2]);
}

// @lc code=end

