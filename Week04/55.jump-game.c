/*
 * @lc app=leetcode.cn id=55 lang=c
 *
 * [55] 跳跃游戏
 */

// @lc code=start

bool canJump(int* nums, int numsSize)
{
    int i, rightmost ;

    if (numsSize <= 0) {
        return true;
    }

    if (numsSize == 1) {
        return true;
    }

    rightmost = nums[0];
    for (i = 1; i <= rightmost; i++) {
        rightmost = fmax(rightmost, nums[i] + i);
        if (rightmost >= numsSize - 1) {
            return true;
        }
    }
    return false;
}
// @lc code=end

