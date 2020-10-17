/*
 * @lc app=leetcode.cn id=456 lang=c
 *
 * [456] 132模式
 */

// @lc code=start

//#define N 20
int *g_stack, g_top = -1, g_size = 0;
bool find132pattern(int* nums, int numsSize)
{
    int i, ai, aj, ak, min = INT_MAX;

    if (numsSize < 3) {
        return false;
    }
    g_top = 0;
    g_stack = calloc(numsSize+1, sizeof(int));
    for (aj = 0; aj < numsSize; aj++) {
        min = fmin(min, nums[aj]);
        if (min == nums[aj]) {
            // 找到新的最小值
            continue;
        }

        for (ak = numsSize - 1; ak > aj; ak--) {
            if (nums[ak] <nums[aj] && nums[ak] > min) {
                return true;
            }
            /*
            for (ak = aj + 1; ak < numsSize; ak++) {
                if (nums[ak] <nums[aj] && nums[ak] > nums[i]) {
                    return true;
                }
            }
            */
        }
    }

    return false;
}
// @lc code=end

