/*
 * @lc app=leetcode.cn id=75 lang=c
 *
 * [75] 颜色分类
 */

// @lc code=start


void Swap (int *nums, int i, int j)
{
    int t;
    t = nums[i]; nums[i] = nums[j]; nums[j] = t;
}

void sortColors(int* nums, int numsSize)
{
    int i, j, k;

    // i the end of 0,
    // j the start of 2
    // k the end of 1

    i = 0;
    j = numsSize - 1;
    k = 0;

    while (k <= j) {
        if (nums[k] == 0) {
            Swap(nums, k, i);
            i++;
            k++;
        } else if (nums[k] == 2) {
            Swap(nums, k, j);
            j--;
        } else {
            k++;
        }
    }
}
// @lc code=end

