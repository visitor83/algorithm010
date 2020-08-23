/*
 * @lc app=leetcode.cn id=1011 lang=c
 *
 * 传送带上的包裹必须在 D 天内从一个港口运送到另一个港口。

传送带上的第 i 个包裹的重量为 weights[i]。每一天，我们都会按给出重量的顺序往传送带上装载包裹。我们装载的重量不会超过船的最大运载重量。

返回能在 D 天内将传送带上的所有包裹送达的船的最低运载能力。

 

示例 1：

输入：weights = [1,2,3,4,5,6,7,8,9,10], D = 5
输出：15
解释：
船舶最低载重 15 就能够在 5 天内送达所有包裹，如下所示：
第 1 天：1, 2, 3, 4, 5
第 2 天：6, 7
第 3 天：8
第 4 天：9
第 5 天：10

请注意，货物必须按照给定的顺序装运，因此使用载重能力为 14 的船舶并将包装分成 (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) 是不允许的。 
示例 2：

输入：weights = [3,2,2,4,1,4], D = 3
输出：6
解释：
船舶最低载重 6 就能够在 3 天内送达所有包裹，如下所示：
第 1 天：3, 2
第 2 天：2, 4
第 3 天：1, 4
示例 3：

输入：weights = [1,2,3,1,1], D = 4
输出：3
解释：
第 1 天：1
第 2 天：2
第 3 天：3
第 4 天：1, 1
 * [1011] 在 D 天内送达包裹的能力
 */

// @lc code=start


int shipWithinDays(int* weights, int weightsSize, int D){
// 设计的能够淘汰一半元素
bool Check(int *arr, int alen, int pvoit, int D ) {
    int i, count, sum = 0;
    for (i = 0, count = 1; i < alen; i++) {
        // 漏掉了下面这一行
        if (arr[i] > pvoit ) return false;
        if (sum + arr[i] > pvoit) {
           count++;
           sum = arr[i];
        } else {
            sum += arr[i];
        }
    }
    return  count <= D ? true : false;
}

int shipWithinDays(int* weights, int weightsSize, int D){
    int i, j, ans, maxVal = 0, m;
    for ( i = 0; i < weightsSize; i++) {
        maxVal += weights[i];
        //if (weights[i] > maxVal) { maxVal = weights[i];}
    }
    //printf(" avg %d\n", maxVal / D);
    i = 1; j = maxVal+1;
    ans = 0;
    while (i <= j) {
        m = i + (j - i) /2;
        // m 为分割值， 扫描一遍数组， 判断是否能分割成D天
        //printf(" i %d j %d m %d\n", i, j, m);
        if (Check(weights, weightsSize,  m, D)) {
            ans = m;
            j = m - 1;
        } else {
            i = m + 1;
        }
    }

    return ans;
}
}
// @lc code=end

