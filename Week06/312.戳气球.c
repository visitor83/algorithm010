/*
 * @lc app=leetcode.cn id=312 lang=c
 *
 * [312] 戳气球
 */

// @lc code=start
int func(int *nums, int left, int right)
{
    int ans = 0, i;
    // terminator
    if (left + 1 >= right) {
        return 0;
    }

    for (i = left + 1; i < right; i++) {
        //int data = nums[i - 1] * nums[i] * nums[i + 1];
        int data = nums[left] * nums[i] * nums[right];
        ans = fmax(ans, data + func(nums, left, i) + func(nums, i, right));
    }

    return ans;
}

int maxCoins(int *a, int numsSize)
{
    int i;
    int *nums ;
    
    nums = (int*)calloc(numsSize+2, sizeof(int));
    for (i = 0; i < numsSize; i++) {
        nums[i+1] = a[i];
    }
    printf(" %d\n", i);
    nums[0] = nums[i+1] = 1;
    return func(nums, 0, i+1);
}


// @lc code=end

