/*
 * @lc app=leetcode.cn id=121 lang=c
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

// 贪心
int maxProfit2(int *prices, int pricesSize)
{
    int ans = 0, cur = 0;
    int low = INT_MAX;
    if (pricesSize == 1) {
        return 0;
    }
    // 找到从左侧开始最小点，保持，j 向右侧找与之最大差
    for (int i = 0; i < pricesSize; i++) {
        if (low > prices[i]) {
            low = prices[i];
        } else {
            // 只能一次买卖
            ans = fmax(prices[i] - low, ans);
        }
    }
    return ans;
}
// dp
/*
// 最优子结构: 通过子问题的最值，选取得到最后的解
//            -- 第i天买还是卖
// 重叠子问题:
// 有无后效性：
/* 穷举状态：目的根据选择更新状态
    - 天数、交易次数、持有状态
选择：
    - 买、卖、不处理
第i天
     */

int maxProfit(int *prices, int pricesSize)
{
    int i;
    int **dp;

    if (pricesSize <= 1) {
        return 0;
    }

    dp = calloc(2, sizeof(int *));
    for (i = 0; i < 2; i++) {
        dp[i] = calloc(pricesSize + 1, sizeof(int));
    }
    // basecase,
    //
    dp[0][0] = 0;
    dp[1][0] = -prices[0];

    // dp[i][0/1] - 当天持有股票 的利润
    for (i = 1; i < pricesSize; i++) {
        if (i < 0) {
            printf("xxx\n");
        }
        // 手里没有股票 -   前一天没股票，第i天也没买
        //            -   前一天有股票， 第i天卖了, 利润 更新？？
        dp[0][i] = fmax(dp[0][i - 1], prices[i] + dp[1][i - 1]);
        // 手里有股票 - 前一天有股票，第i天啥也没干
        // - 前一天没股票，第i天买
        // dp[i][1] = fmax(dp[i-1][1], dp[i-1][0] - prices[i]) ;
        dp[1][i] = dp[1][i] + fmax(dp[1][i - 1], -prices[i]);
    }
    // 卖了最后一个利润大
    return dp[0][pricesSize - 1];
}

int maxProfit(int* prices, int pricesSize){

}


// @lc code=end

