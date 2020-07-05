/*
 * @lc app=leetcode.cn id=122 lang=c
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
int maxProfit(int* prices, int pricesSize)
{
    int i,  buy, sell, sum;
    // 单调栈，反序递增减，当5出现时，弹出 如果是3 < 6直接弹出6-3，
    // 1 < 5 ， 弹出5 - 1 = 4 
    // 7，4

    //  左侧最小值
    i = 0;
    sum = 0;
    while (i < pricesSize - 1) {
        // 找右边最小的点
        while (i < pricesSize - 1 && prices[i+1] <= prices[i]) {
            i++;
        }
        buy =  prices[i];
        while (i < pricesSize -1  && prices[i+1] > prices[i]) {
            i++;
        }
        sell = prices[i];
        
        sum += sell - buy;
    }
    return sum;
}
// @lc code=end

