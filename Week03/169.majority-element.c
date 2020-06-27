/*
 * @lc app=leetcode.cn id=169 lang=c
 *
 * [169] 多数元素
 */

// @lc code=start
int Majority(int *nums, int left, int right)
{
    int m, lm, rm;
    int lCnt, rCnt;

    /* terminator */
    if (left >= right) {
        return nums[left];
    }

    m = left + (right - left) / 2;

    /* drill down */
    lm = Majority(nums, left, m);
    rm = Majority(nums, m + 1, right);

    //printf("lm %d, rm %d\n", lm, rm);
    /* current level logic , merge */
    rCnt = 0;
    lCnt = 0;
    for (int i = left; i < right + 1; i++ ) {
        if (nums[i] == lm) {
            lCnt++;
        } else if (nums[i] == rm) {
            rCnt++;
        }  
    }

    return lCnt > rCnt ? lm : rm;
}

int majorityElement(int* nums, int numsSize)
{
    if (!nums) {
        return 0;
    }
    if (numsSize == 0) {
        return 0;
    }

    return Majority(nums, 0, numsSize - 1);
}

// @lc code=end

