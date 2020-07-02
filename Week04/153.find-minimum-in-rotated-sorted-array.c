/*
 * @lc app=leetcode.cn id=153 lang=c
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

请找出其中最小的元素。

你可以假设数组中不存在重复元素。

示例 1:

输入: [3,4,5,1,2]
输出: 1
示例 2:

输入: [4,5,6,7,0,1,2]
输出: 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start


int findMin(int* nums, int numsSize)
{
    int i,j, m;

    i = 0;
    j = numsSize - 1;
    while (i < j) {
        m = i + (j - i) / 2;
        printf("m %d, i %d, j %d\n", m, i, j);

        if (nums[numsSize- 1] < nums[m]) {
            i = m + 1;
        } else {
            j = m;
        }
    }

    return nums[i];
}

// @lc code=end

