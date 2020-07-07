/*
给定一个排序好的数组，两个整数 k 和 x，从数组中找到最靠近 x（两数之差最小）的 k 个数。返回的结果必须要是按升序排好的。如果有两个数与 x 的差值一样，优先选择数值较小的那个数。

示例 1:

输入: [1,2,3,4,5], k=4, x=3
输出: [1,2,3,4]
 

示例 2:

输入: [1,2,3,4,5], k=4, x=-1
输出: [1,2,3,4]
 

说明:

k 的值为正数，且总是小于给定排序数组的长度。
数组不为空，且长度不超过 104
数组里的每个元素与 x 的绝对值不超过 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-k-closest-elements
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
int *findClosestElements(int *arr, int arrSize, int k, int x, int *returnSize)
{
    int *ans;
    int i, j, m, pivot = -1;

    ans = calloc(k, sizeof(int));
    *returnSize = k;
    if (arr[0] >= x) {
        memcpy(ans, arr, sizeof(int) * k);
    } else if (arr[arrSize - 1] <= x) {
        // [arrSize - k , arrSize - 1]
        memcpy(ans, &arr[arrSize - k], sizeof(int) * k);
    } else {
        i = 0;
        j = arrSize - 1;
        while (i <= j) {
            m = i + (j - i) / 2;
            if (arr[m] == x) {
                pivot = m;
                break;
            } else if (arr[m] < x) {
                i = m + 1;
            } else {
                j = m - 1;
            }
        }

        int cnt = 0;
        i = fmax(0, m - k - 1);
        j = fmin(arrSize - 1, m + k - 1);
        while (j - i > k - 1) {
            if (x - arr[i] <= arr[j] - x) {
                j--;
            } else {
                i++;
            }
            cnt++;
        }
        memcpy(ans, &arr[i], sizeof(int) * k);
    }

    return ans;
}