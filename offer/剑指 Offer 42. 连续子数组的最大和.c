
// 子数组的累加和问题
int maxSubArray2(int* nums, int numsSize){
    int j,  sum, ans;

// 如果是 负数？？, 子数组和下降
    ans = INT_MIN;
    for(j = 0, sum = 0; j < numsSize; j++) {
        sum += nums[j];
        ans = fmax(ans, sum);
        if (sum < 0) {
            sum = 0;
        }
        j++;
    }
    return ans;
}

/* 
dp[i] : [0,i] 最大连续子序列和
 最优子结构: dp[i] 加入不加入子序列,  dp[i-1] <0  , dp[i]  = 0 + A[i]
  dp[i-1] >0 , dp[i] = dp[i+1] + A[i]
  以i为结尾的连续子序列
   重复子问题： 
   无后效性:
   状态转移方程:  */
int maxSubArrayDP(int* nums, int numsSize){
    int *dp, ans;

    dp = calloc(numsSize + 1, sizeof(int));
    dp[0] = nums[0];

    ans = INT_MIN;
    ans = fmax(ans, dp[0]);
    for (int i = 1; i < numsSize ; i++) {
        dp[i] = (dp[i-1]  < 0 ? 0 : dp[i-1])  + nums[i];
        ans = fmax(ans, dp[i]);
        /* code */
    }
    return  ans;
}

// 分治算法 O(n*lgN)
// 最大子序列[lo, hi]在左边，右边, 或者跨越中间
int myfunc(int *nums, int lo, int hi) {
    int pivot, lsum, rsum;
    // terminator
    if (nums[lo] >= nums[hi]) {
        return nums[lo];
    }

    pivot = lo + ((hi - lo) >> 1);

    lsum = myfunc(nums, lo, pivot);
    rsum = myfunc(nums, pivot +1, hi);

    // 包含pivot点的连续子序列和, 必须i 从pivot开始
    int sum = 0, i, j, lcross, rcross;
    lcross = rcross = INT_MIN;
    for (i = pivot ; i >= lo; i--) {
        sum += nums[i];
        lcross = fmax(lcross, sum);
    }
    sum = 0;
    for (j = pivot + 1; j <= hi; j++) {
        sum += nums[j];
        rcross = fmax(rcross, sum);
    }
    return fmax(lsum , fmax( rsum , lcross + rcross));
}
int maxSubArray(int* nums, int numsSize){
    return myfunc(nums, 0, numsSize - 1);
}